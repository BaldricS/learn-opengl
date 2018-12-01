#pragma once


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

        unsigned int handle() const;
    
        void unbind();

    private:
        unsigned int vao;
    };
}