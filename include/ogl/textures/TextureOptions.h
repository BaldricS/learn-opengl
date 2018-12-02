#pragma once

#include "ogl/textures/TextureMaxFilter.h"
#include "ogl/textures/TextureMinFilter.h"
#include "ogl/textures/TextureWrap.h"

#include <glad/glad.h>

namespace ogl::textures
{
    struct TextureOptions
    {
        TextureWrap coord_s = TextureWrap::Repeat;
        TextureWrap coord_t =  TextureWrap::Repeat;
        TextureMinFilter min_filter = TextureMinFilter::Linear;
        TextureMaxFilter max_filter = TextureMaxFilter::Linear;
        bool gen_mip_map = true;
    };
}