#pragma once

#include <glad/glad.h>

#include <filesystem>

namespace ogl::textures
{
    struct TextureOptions;

    class Texture
    {
    public:
        Texture();

        Texture(Texture const &) = delete;

        Texture(Texture && other);

        ~Texture();

        Texture & operator=(Texture const &) = delete;

        Texture & operator=(Texture && other);

        void bind();

        GLuint handle() const;

        void load_data(std::filesystem::path const & imagePath);

        void load_data(std::filesystem::path const & imagePath, TextureOptions const & options);

        void unbind();

    private:
        GLuint texture;
    };
}