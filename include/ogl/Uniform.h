#pragma once

#include "ogl/Program.h"

#include <glad/glad.h>

#include <stdexcept>
#include <string>
#include <type_traits>

namespace ogl
{
    class Program;

    template<typename Scalar, int Size = 1>
    class Uniform
    {
    public:
        Uniform(Program const & program, std::string const & uniformName) :
            uniformLoc(glGetUniformLocation(program.handle(), uniformName.c_str()))
        {
            if (uniformLoc == -1)
            {
                throw std::invalid_argument("Uniform " + uniformName + " not found for program " + std::to_string(program.handle()));
            }
        }

        template<typename = std::enable_if_t<std::is_floating_point_v<Scalar> && Size == 4>>
        void set(float x, float y, float z, float w)
        {
            glUniform4f(uniformLoc, x, y, z, w);
        }

        template<typename = std::enable_if_t<std::is_floating_point_v<Scalar> && Size == 1>>
        void set(float x)
        {
            glUniform1f(uniformLoc, x);
        }

        template<typename = std::enable_if_t<std::is_integral_v<Scalar> && Size == 1>>
        void set(int v0)
        {
            glUniform1i(uniformLoc, v0);
        }

    private:
        GLint uniformLoc;
    };
}