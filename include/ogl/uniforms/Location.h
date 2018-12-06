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

        GLuint get_location() const;

    private:
        GLuint loc;
    };
}