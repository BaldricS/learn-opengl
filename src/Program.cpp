#include "ogl/Program.h"

#include "ogl/Shader.h"

#include <glad/glad.h>

#include <stdexcept>
#include <utility>

namespace ogl
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

    unsigned int Program::handle() const
    {
        return program;
    }

    void Program::link()
    {
        glLinkProgram(program);

        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);

        if (success == GL_TRUE)
        {
            return;
        }

        int logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

        std::string log;
        log.resize(logLength);

        glGetProgramInfoLog(program, logLength, NULL, log.data());

        throw std::runtime_error("Error linking program. Error message: " + log);
    }
}