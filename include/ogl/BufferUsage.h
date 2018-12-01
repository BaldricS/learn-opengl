#pragma

#include <glad/glad.h>

namespace ogl
{
    enum class BufferUsage
    {
        Dynamic = GL_DYNAMIC_DRAW,
        Static = GL_STATIC_DRAW,
        Stream = GL_STREAM_DRAW
    };
}