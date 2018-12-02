#include "ogl/utils/TextureBuilder.h"

namespace ogl::utils
{
    textures::Texture TextureBuilder::build_texture(std::filesystem::path const & texture_path) const
    {
        return textures::Texture(texture_path, options);
    }

    TextureBuilder & TextureBuilder::set_max_filter(textures::TextureMaxFilter max_filter)
    {
        options.max_filter = max_filter;

        return *this;
    }

    TextureBuilder & TextureBuilder::set_min_filter(textures::TextureMinFilter min_filter)
    {
        options.min_filter = min_filter;

        return *this;
    }

    TextureBuilder & TextureBuilder::set_wrap_s(textures::TextureWrap s_wrap)
    {
        options.coord_s = s_wrap;

        return *this;
    }

    TextureBuilder & TextureBuilder::set_wrap_t(textures::TextureWrap t_wrap)
    {
        options.coord_t = t_wrap;

        return *this;
    }

    TextureBuilder & TextureBuilder::set_mip_map(bool gen_mip_map)
    {
        options.gen_mip_map = gen_mip_map;

        return *this;
    }
}