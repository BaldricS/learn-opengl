#include "ogl/Buffer.h"

namespace ogl
{
    Buffer::Buffer(GLenum bufferType_) :
        bufferType(bufferType_)
    {
        glGenBuffers(1, &vbo);
    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &vbo);
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