#pragma once

#include <filesystem>

namespace ogl
{
    class ImageHandle
    {
    public:
        explicit ImageHandle(std::filesystem::path const & imagePath);

        ~ImageHandle();

        unsigned char const * get_data() const;
        
        int get_channels() const;

        int get_height() const;

        int get_width() const;

    private:
        int height = 0;
        unsigned char * image_data = nullptr;
        int number_channels = 0;
        int width = 0;
    };
}