#pragma once

#include "ogl/Program.h"

#include <string>

namespace ogl::utils
{
    Program createProgram(std::string const & vertexSrc, std::string const & fragmentSrc);
}