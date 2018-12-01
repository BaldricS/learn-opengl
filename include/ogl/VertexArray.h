#pragma once

#include <glad/glad.h>

namespace ogl
{
    class VertexArray
    {
    public:
        VertexArray();

        VertexArray(VertexArray const &) = delete;

        VertexArray(VertexArray && other);

        ~VertexArray();

        VertexArray & operator=(VertexArray const &) = delete;

        VertexArray & operator=(VertexArray && other);

        void bind();

        GLuint handle() const;
    
        void unbind();

    private:
        GLuint vao = 0;
    };
}