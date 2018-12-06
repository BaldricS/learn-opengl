#pragma once

#include <glad/glad.h>

namespace ogl::shaders
{
    enum class ShaderType
    {
        Fragment = GL_FRAGMENT_SHADER,
        Vertex = GL_VERTEX_SHADER
    };
}