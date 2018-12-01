#include "ogl/Shader.h"

#include <stdexcept>
#include <utility>

namespace ogl
{
    Shader::Shader(ShaderType shaderType) :
        shader(glCreateShader(static_cast<GLenum>(shaderType)))
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

        GLint compileStatus;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

        if(compileStatus == GL_TRUE)
        {
            return;
        }

        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

        std::string log;
        log.resize(logLength);

        glGetShaderInfoLog(shader, logLength, NULL, log.data());

        throw std::runtime_error("Could not compile shader. Error Message: " + log);
    }

    GLuint Shader::handle() const
    {
        return shader;
    }
}