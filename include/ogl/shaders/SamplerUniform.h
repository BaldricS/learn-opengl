#pragma once

#include "ogl/shaders/UniformLocation.h"

namespace ogl::textures
{
    class TextureUnit;
}

namespace ogl::shaders
{
    class SamplerUniform : private UniformLocation
    {
    public:
        using UniformLocation::UniformLocation;

        void set(textures::TextureUnit const & unit);
    };
}