#include "ogl/textures/TextureUniform.h"

#include "ogl/textures/Texture.h"

#include <glad/glad.h>

#include <stdexcept>

namespace ogl::textures
{
    TextureUniform::TextureUniform(Program & prog, std::string const & uniformName, Texture & tex_, unsigned char texture_unit_) :
        uniform(prog, uniformName),
        tex(tex_),
        texture_unit(texture_unit_)
    {
        if (texture_unit > 79)
        {
            throw std::invalid_argument("Texture unit must be 79 or less.");
        }
    }
    
    void TextureUniform::activate()
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        tex.bind();
    }

    void TextureUniform::set_uniform()
    {
        uniform.set(texture_unit);
    }
}