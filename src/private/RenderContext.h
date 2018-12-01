#pragma once

namespace ogl
{
    class RenderContext
    {
    public:
        explicit RenderContext(int majorVersion = 3, int minorVersion = 3);

        ~RenderContext();
    };
}