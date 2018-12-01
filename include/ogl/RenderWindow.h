#pragma once

#include <memory>

struct GLFWwindow;

namespace ogl
{
    class RenderContext;

    class RenderWindow
    {
    public:
        explicit RenderWindow(int majorVersion = 3, int minorVersion = 3, int width = 800, int height = 600);

        void run() const;

    private:
        GLFWwindow * window = nullptr;

        std::unique_ptr<RenderContext> context = nullptr;
    };
}