#pragma once

#include "ogl/uniforms/Location.h"

namespace ogl::textures
{
    class TextureUnit;
}

namespace ogl::uniforms
{
    class Sampler2D : private Location
    {
    public:
        using Location::Location;

        void set(textures::TextureUnit const & unit);
    };
}