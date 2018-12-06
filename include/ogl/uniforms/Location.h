#pragma once

#include <glad/glad.h>

#include <string>

namespace ogl::shaders
{
    class Program;
}

namespace ogl::uniforms
{
    class Location
    {
    public:
        Location(shaders::Program const & prog, std::string const & uniform_name);

        GLint get_location() const;

    private:
        GLint loc;
    };
}