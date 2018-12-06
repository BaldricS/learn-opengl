#include "ogl/shaders/SamplerUniform.h"

#include "ogl/textures/TextureUnit.h"

#include <glad/glad.h>

namespace ogl::shaders
{
    void SamplerUniform::set(textures::TextureUnit const & texture_unit)
    {
        glUniform1i(get_location(), texture_unit.get_texture_unit());
    }
}