#pragma once

#include <ogl/Uniform.h>

namespace ogl
{
    class Program;
}

namespace ogl::textures
{
    class Texture;

    class TextureUniform
    {
    public:
        TextureUniform(Program & prog, std::string const & uniformName, Texture & tex, unsigned char texture_unit);
        
        void bind();

        void set_uniform();

        void unbind();

    private:
        Uniform<int> uniform;

        Texture & tex;

        unsigned char texture_unit;
    };
}