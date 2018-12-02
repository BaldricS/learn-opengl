#pragma once

#include "ogl/textures/Texture.h"
#include "ogl/textures/TextureMaxFilter.h"
#include "ogl/textures/TextureMinFilter.h"
#include "ogl/textures/TextureOptions.h"
#include "ogl/textures/TextureWrap.h"

#include <filesystem>

namespace ogl::utils
{
    class TextureBuilder
    {
    public:
        textures::Texture build_texture(std::filesystem::path const & texture_path) const;

        TextureBuilder & set_max_filter(textures::TextureMaxFilter max_filter);

        TextureBuilder & set_min_filter(textures::TextureMinFilter min_filter);

        TextureBuilder & set_wrap_s(textures::TextureWrap s_wrap);

        TextureBuilder & set_wrap_t(textures::TextureWrap t_wrap);

        TextureBuilder & set_mip_map(bool gen_mip_map);

    private:
        textures::TextureOptions options;
    };
}