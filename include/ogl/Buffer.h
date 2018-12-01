#pragma

#include "ogl/BufferType.h"

namespace ogl
{
    class Buffer
    {
    public:
        explicit Buffer(BufferType bufferType = ArrayBuffer);

        Buffer(Buffer const &) = delete;

        Buffer(Buffer && other);

        ~Buffer();

        Buffer & operator=(Buffer const &) = delete;

        Buffer & operator=(Buffer && other);

        void bind();

        void unbind();

        unsigned int handle() const;

    private:
        unsigned int bufferType;

        unsigned int vbo = 0;
    };
}