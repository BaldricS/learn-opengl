#pragma once

#include "ogl/Program.h"

#include <glad/glad.h>

#pragma warning(push)
#pragma warning(disable: 4201)
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma warning(pop)

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

        template<typename = std::enable_if_t<std::is_same_v<Scalar, float> && Size == 4>>
        void set(float x, float y, float z, float w)
        {
            glUniform4f(uniformLoc, x, y, z, w);
        }

        template<typename = std::enable_if_t<std::is_same_v<Scalar, float> && Size == 1>>
        void set(float x)
        {
            glUniform1f(uniformLoc, x);
        }

        template<typename = std::enable_if_t<std::is_same_v<Scalar, int> && Size == 1>>
        void set(int v0)
        {
            glUniform1i(uniformLoc, v0);
        }

        template<typename = std::enable_if_t<std::is_same_v<Scalar, glm::mat4> && Size == 1>>
        void set(glm::mat4 const & mat)
        {
            glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(mat));
        }

    private:
        GLint uniformLoc;
    };
}