#include "ogl/Buffer.h"

#include <glad/glad.h>

#include <stdexcept>
#include <utility>

namespace
{
    GLenum translateBufferType(ogl::BufferType type)
    {
        switch (type)
        {
            case ogl::BufferType::ArrayBuffer:
                return GL_ARRAY_BUFFER;
            default:
                throw std::invalid_argument("Unhandle buffer type.");
        }
    }
}

namespace ogl
{
    Buffer::Buffer(BufferType bufferType_) :
        bufferType(translateBufferType(bufferType_))
    {
        glGenBuffers(1, &vbo);
    }

    Buffer::Buffer(Buffer && other) :
        vbo(std::exchange(other.vbo, 0))
    {
    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &vbo);
    }

    Buffer & Buffer::operator=(Buffer && other)
    {
        vbo = std::exchange(other.vbo, 0);

        return *this;
    }

    void Buffer::bind()
    {
        glBindBuffer(bufferType, vbo);
    }
    
    GLuint Buffer::handle() const
    {
        return vbo;
    }

    void Buffer::unbind()
    {
        glBindBuffer(bufferType, 0);
    }
}