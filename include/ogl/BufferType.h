#pragma once

#include <glad/glad.h>

namespace ogl
{
    enum class BufferType
    {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER
    };
}