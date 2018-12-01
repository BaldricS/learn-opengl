#include "ogl/Buffer.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace ogl
{
    Buffer::Buffer(BufferType bufferType_) :
        bufferType(static_cast<GLenum>(bufferType_))
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
        std::cout << sizeInBytes << std::endl;

        glBufferData(
            bufferType,
            static_cast<GLsizeiptr>(sizeInBytes),
            data,
            static_cast<GLenum>(bufferUsage)
        );
    }
}