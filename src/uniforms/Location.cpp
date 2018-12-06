#include "ogl/uniforms/Location.h"

#include "ogl/shaders/Program.h"

#include <stdexcept>

namespace ogl::uniforms
{
    Location::Location(shaders::Program const & prog, std::string const & uniform_name) :
        loc(glGetUniformLocation(prog.handle(), uniform_name.c_str()))
    {
        if (loc == -1)
        {
            throw std::invalid_argument("Uniform " + uniform_name + " not found for program " + std::to_string(prog.handle()));
        }
    }

    GLint Location::get_location() const
    {
        return loc;
    }
}