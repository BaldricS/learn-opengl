#include "ogl/textures/TextureUnit.h"

#include "ogl/textures/Texture.h"

#include <glad/glad.h>

#include <stdexcept>

namespace ogl::textures
{
    TextureUnit::TextureUnit(Texture & tex_, unsigned char texture_unit_) :
        tex(tex_),
        texture_unit(texture_unit_)
    {
        if (texture_unit > 79)
        {
            throw std::invalid_argument("Texture unit must be 79 or less.");
        }
    }
    
    void TextureUnit::bind()
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        tex.bind();
    }

    unsigned char TextureUnit::get_texture_unit() const
    {
        return texture_unit;
    }

    void TextureUnit::unbind()
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        tex.unbind();
    }
}