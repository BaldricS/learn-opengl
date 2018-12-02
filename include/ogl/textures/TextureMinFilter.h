#pragma once

namespace ogl::textures
{
    enum class TextureMinFilter
    {
        Nearest = GL_NEAREST,
        Linear = GL_LINEAR,
        NearestNearest = GL_NEAREST_MIPMAP_NEAREST,
        LinearNearest = GL_LINEAR_MIPMAP_NEAREST,
        NearestLinear = GL_NEAREST_MIPMAP_LINEAR,
        LinearLinear = GL_LINEAR_MIPMAP_LINEAR
    };
}