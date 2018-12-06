#pragma once

#include <glad/glad.h>

namespace ogl::shaders
{
    class Shader;

    class Program
    {
    public:
        Program();

        Program(Program const &) = delete;

        Program(Program && other);

        ~Program();

        Program & operator=(Program const &) = delete;

        Program & operator=(Program && other);

        void add_shader(Shader const & shader);

        void bind();

        GLuint handle() const;

        void link();

        void unbind();

    private:
        GLuint program;
    };
}