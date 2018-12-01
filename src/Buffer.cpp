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

    GLenum translateBufferUsage(ogl::BufferUsage usage)
    {
        switch(usage)
        {
            case ogl::BufferUsage::Static:
                return GL_STATIC_DRAW;
            case ogl::BufferUsage::Stream:
                return GL_STREAM_DRAW;
            case ogl::BufferUsage::Dynamic:
                return GL_DYNAMIC_DRAW;
            default:
                throw std::invalid_argument("Unhandle usage type.");
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

    void Buffer::load_data(void * data, std::size_t sizeInBytes, BufferUsage bufferUsage)
    {
        glBufferData(
            vbo,
            static_cast<GLsizeiptr>(sizeInBytes),
            data,
            translateBufferUsage(bufferUsage)
        );
    }
}