#include "ogl/VertexArray.h"

#include <glad/glad.h>

#include <utility>

namespace ogl
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &vao);
    }

    VertexArray::VertexArray(VertexArray && other) :
        vao(std::exchange(other.vao, 0))
    {
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &vao);
    }

    VertexArray & VertexArray::operator=(VertexArray && other)
    {
        vao = std::exchange(other.vao, 0);

        return *this;
    }

    void VertexArray::bind()
    {
        glBindVertexArray(vao);
    }

    unsigned int VertexArray::handle() const
    {
        return vao;
    }
    
    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }
}