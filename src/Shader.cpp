#include "ogl/Shader.h"

#include <glad/glad.h>

#include <stdexcept>
#include <utility>

namespace
{
    GLenum translateShaderType(ogl::ShaderType shaderType)
    {
        switch (shaderType)
        {
            case ogl::ShaderType::Fragment:
                return GL_FRAGMENT_SHADER;
            case ogl::ShaderType::Vertex:
                return GL_VERTEX_SHADER;
            default:
                throw std::invalid_argument("Unhandled shader type.");
        }
    }
}

namespace ogl
{
    Shader::Shader(ShaderType shaderType) :
        shader(glCreateShader(translateShaderType(shaderType)))
    {
    }

    Shader::Shader(ShaderType shaderType, std::string const & source) :
        Shader(shaderType)
    {
        compile(source);
    }

    Shader::Shader(Shader && other) :
        shader(std::exchange(other.shader, 0))
    {
    }

    Shader::~Shader()
    {
        glDeleteShader(shader);
    }

    Shader & Shader::operator=(Shader && other)
    {
        shader = std::exchange(other.shader, 0);

        return *this;
    }

    void Shader::compile(std::string const & source)
    {
        char const * const src = source.c_str();

        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);

        int compileStatus;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

        if(compileStatus == GL_TRUE)
        {
            return;
        }

        int logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

        std::string log;
        log.resize(logLength);

        glGetShaderInfoLog(shader, logLength, NULL, log.data());

        throw std::runtime_error("Could not compile shader. Error Message: " + log);
    }

    unsigned int Shader::handle() const
    {
        return shader;
    }
}