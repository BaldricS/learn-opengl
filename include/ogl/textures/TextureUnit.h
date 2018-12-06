#pragma once

namespace ogl::textures
{
    class Texture;

    class TextureUnit
    {
    public:
        TextureUnit(Texture & tex, unsigned char texture_unit);
        
        void bind();

        unsigned char get_texture_unit() const;

        void unbind();

    private:
        Texture & tex;

        unsigned char texture_unit;
    };
}