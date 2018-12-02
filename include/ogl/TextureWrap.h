#pragma once

#include <glad/glad.h>

namespace ogl
{
    enum class TextureWrap
    {
        ClampEdge = GL_CLAMP_TO_EDGE,
        ClampBorder = GL_CLAMP_TO_BORDER,
        MirroredRepeat = GL_MIRRORED_REPEAT,
        Repeat = GL_REPEAT,
        MirroredClampEdge = GL_MIRROR_CLAMP_TO_EDGE
    };
}