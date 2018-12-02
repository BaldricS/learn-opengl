#pragma once

#include <glad/glad.h>

#include <filesystem>

namespace ogl::textures
{
    class Texture
    {
    public:
        Texture();

        Texture(Texture const &) = delete;

        Texture(Texture && other);

        ~Texture();

        Texture & operator(Texture const &) = delete;

        Texture & operator(Texture && other);

        GLuint handle() const;

    private:
        GLuint texture;
    };
}