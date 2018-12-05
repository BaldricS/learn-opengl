#pragma once

#include "ogl/BufferType.h"
#include "ogl/BufferUsage.h"

#include <glad/glad.h>

#include <vector>

namespace ogl
{
    class Buffer
    {
    public:
        explicit Buffer(BufferType bufferType = BufferType::ArrayBuffer);

        Buffer(Buffer const &) = delete;

        Buffer(Buffer && other);

        ~Buffer();

        Buffer & operator=(Buffer const &) = delete;

        Buffer & operator=(Buffer && other);

        void bind();

        GLuint handle() const;

        template<typename T>
        void load_data(std::vector<T> const & d, BufferUsage usage = BufferUsage::Static)
        {
            load_data((void *)d.data(), d.size() * sizeof(T), usage);
        }

        void unbind();

    private:
        GLenum bufferType;

        GLuint vbo = 0;

        void load_data(void * data, std::size_t sizeInBytes, BufferUsage usage);
    };
}