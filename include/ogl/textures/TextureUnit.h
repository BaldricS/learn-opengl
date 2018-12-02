#pragma once

#include "ogl/Uniform.h"

namespace ogl::textures
{
    class Texture;

    class TextureUnit
    {
    public:
        TextureUnit(Texture & tex, unsigned char texture_unit);
        
        void bind();

        void set(Uniform<int> & samplerUniform);

        void unbind();

    private:
        Texture & tex;

        unsigned char texture_unit;
    };
}