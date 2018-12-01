#pragma once

#include "ogl/ShaderType.h"

#include <glad/glad.h>

#include <string>

namespace ogl
{
    class Shader
    {
    public:
        explicit Shader(ShaderType shaderType);

        Shader(ShaderType shaderType, std::string const & source);

        Shader(Shader const &) = delete;

        Shader(Shader && other);

        ~Shader();

        Shader & operator=(Shader const &) = delete;

        Shader & operator=(Shader && other);

        void compile(std::string const & source);

        GLuint handle() const;

    private:
        GLuint shader = 0;
    };
}