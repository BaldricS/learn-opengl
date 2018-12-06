#pragma once

#include "ogl/uniforms/Location.h"

#include <glm/fwd.hpp>

namespace ogl::uniforms
{
    class Mat4 : private Location
    {
    public:
        using Location::Location;

        void set(glm::mat4 const & m);
    };
}