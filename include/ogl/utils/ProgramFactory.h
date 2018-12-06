#pragma once

#include "ogl/shaders/Program.h"

#include <string>

namespace ogl::utils
{
    shaders::Program createProgram(std::string const & vertexSrc, std::string const & fragmentSrc);
}