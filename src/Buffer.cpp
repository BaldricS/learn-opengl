#include "ogl/Buffer.h"

#include <utility>

namespace ogl
{
    Buffer::Buffer(GLenum bufferType_) :
        bufferType(bufferType_)
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

    void Buffer::unbind()
    {
        glBindBuffer(bufferType, 0);
    }

    GLuint Buffer::handle() const
    {
        return vbo;
    }
}