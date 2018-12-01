#include "private/ImageHandle.h"

#include <stb/stb_image.h>

#include <stdexcept>

namespace ogl
{
    ImageHandle::ImageHandle(std::filesystem::path const & image_path)
    {
        if (!std::filesystem::exists(image_path))
        {
            throw std::invalid_argument("Image does not exist at: " + image_path.string());
        }

        image_data = stbi_load(image_path.string().c_str(), &width, &height, &number_channels, 0);
        if (image_data == nullptr)
        {
            throw std::invalid_argument("Image could not be loaded from: " + image_path.string());
        }
    }

    ImageHandle::~ImageHandle()
    {
        stbi_image_free(image_data);
    }

    unsigned char const * ImageHandle::get_data() const
    {
        return image_data;
    }

    int ImageHandle::get_channels() const
    {
        return number_channels;
    }

    int ImageHandle::get_height() const
    {
        return height;
    }

    int ImageHandle::get_width() const
    {
        return width;
    }
}