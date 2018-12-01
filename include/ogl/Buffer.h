#pragma

#include <glad/glad.h>

namespace ogl
{
    class Buffer
    {
    public:
        explicit Buffer(GLenum bufferType = GL_ARRAY_BUFFER);

        Buffer(Buffer const &) = delete;

        Buffer(Buffer && other);

        ~Buffer();

        Buffer & operator=(Buffer const &) = delete;

        Buffer & operator=(Buffer && other);

        void bind();

        void unbind();

        GLuint handle() const;

    private:
        GLenum bufferType;

        GLuint vbo;
    };
}