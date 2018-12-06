#include "ogl/shaders/Program.h"

#include "ogl/shaders/Shader.h"

#include <stdexcept>
#include <utility>

namespace ogl::shaders
{
    Program::Program() :
        program(glCreateProgram())
    {
    }

    Program::Program(Program && other) :
        program(std::exchange(other.program, 0))
    {
    }

    Program::~Program()
    {
        glDeleteProgram(program);
    }

    Program & Program::operator=(Program && other)
    {
        program = std::exchange(other.program, 0);

        return *this;
    }

    void Program::add_shader(Shader const & shader)
    {
        glAttachShader(program, shader.handle());
    }

    void Program::bind()
    {
        glUseProgram(program);
    }

    GLuint Program::handle() const
    {
        return program;
    }

    void Program::link()
    {
        glLinkProgram(program);

        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);

        if (success == GL_TRUE)
        {
            return;
        }

        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

        std::string log;
        log.resize(logLength);

        glGetProgramInfoLog(program, logLength, NULL, log.data());

        throw std::runtime_error("Error linking program. Error message: " + log);
    }

    void Program::unbind()
    {
        glUseProgram(0);
    }
}