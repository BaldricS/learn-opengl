#pragma once

#include <glad/glad.h>

namespace ogl::textures
{
    struct TextureOptions
    {
        TextureWrap textureCoordS = TextureWrap::GL_REPEAT;
        TextureWrap textureCoordT =  TextureWrap::GL_REPEAT;
        TextureMinFilter minFilter = TextureMinFilter::Linear;
        TextureMaxFilter maxFilter = TextureMaxFilter::Linear;
        bool generateMipMap = true;
    };
}