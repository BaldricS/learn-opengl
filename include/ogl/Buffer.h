#pragma

#include <glad/glad.h>

namespace ogl
{
    class Buffer
    {
    public:
        explicit Buffer(GLenum bufferType = GL_ARRAY_BUFFER);

        ~Buffer();

        void bind();

        void unbind();

        GLuint handle() const;

    private:
        GLenum bufferType;

        GLuint vbo;
    };
}