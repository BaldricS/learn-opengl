#pragma once

#include <glad/glad.h>

#include <filesystem>

namespace ogl::textures
{
    struct TextureOptions;

    class Texture
    {
    public:
        explicit Texture(std::filesystem::path const & imagePath);

        Texture(std::filesystem::path const & imagePath, TextureOptions const & options);

        Texture(Texture const &) = delete;

        Texture(Texture && other);

        ~Texture();

        Texture & operator=(Texture const &) = delete;

        Texture & operator=(Texture && other);

        void bind();

        GLuint handle() const;

        void unbind();

    private:
        GLuint texture;
    };
}