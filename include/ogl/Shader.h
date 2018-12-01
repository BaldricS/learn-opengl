#pragma once

#include "ogl/ShaderType.h"

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

        unsigned int handle() const;

    private:
        unsigned int shader = 0;
    };
}