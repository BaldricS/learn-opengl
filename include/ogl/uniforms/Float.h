#pragma once

#include "ogl/uniforms/Location.h"

namespace ogl::uniforms
{
    class Float : private Location
    {
    public:
        using Location::Location;

        void set(float v0);
    };
}