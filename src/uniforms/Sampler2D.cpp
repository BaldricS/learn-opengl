#include "ogl/uniforms/Sampler2D.h"

#include "ogl/textures/TextureUnit.h"

#include <glad/glad.h>

namespace ogl::uniforms
{
    void Sampler2D::set(textures::TextureUnit const & texture_unit)
    {
        glUniform1i(get_location(), texture_unit.get_texture_unit());
    }
}