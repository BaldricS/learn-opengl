#include "ogl/textures/Texture.h"

#include "ogl/textures/TextureOptions.h"

#include "ogl/utils/ScopedBind.h"

#include "private/ImageHandle.h"

#include <utility>

namespace
{
    ogl::textures::TextureOptions & getDefaultOptions()
    {
        static ogl::textures::TextureOptions options;
        return options;
    }

    GLenum getChannels(int numChannels)
    {
        switch(numChannels)
        {
            case 1:
                return GL_RED;
            case 2:
                return GL_RG;
            case 3:
                return GL_RGB;
            case 4:
                return GL_RGBA;
            default:
                return GL_RGB;
        };
    }
}

namespace ogl::textures
{
    Texture::Texture()
    {
        glGenTextures(1, &texture);
    }

    Texture::Texture(Texture && other) :
        texture(std::exchange(other.texture, 0))
    {
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &texture);
    }

    Texture & Texture::operator=(Texture && other)
    {
        texture = std::exchange(other.texture, 0);

        return *this;
    }

    void Texture::bind()
    {
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    GLuint Texture::handle() const
    {
        return texture;
    }

    void Texture::load_data(std::filesystem::path const & imagePath)
    {
        load_data(imagePath, getDefaultOptions());
    }

    void Texture::load_data(std::filesystem::path const & imagePath, TextureOptions const & options)
    {
        ImageHandle img(imagePath);

        utils::ScopedBind bind_texture(*this);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLenum>(options.coord_s));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLenum>(options.coord_t));

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(options.min_filter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(options.max_filter));

        GLenum format = getChannels(img.get_channels());
        glTexImage2D(GL_TEXTURE_2D, 0, format, img.get_width(), img.get_height(), 0, format, GL_UNSIGNED_BYTE, img.get_data());

        if (options.gen_mip_map)
        {
            glGenerateMipmap(GL_TEXTURE_2D);
        }
    }

    void Texture::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}