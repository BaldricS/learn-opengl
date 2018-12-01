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
        
        RenderWindow(RenderWindow const &) = delete;

        RenderWindow(RenderWindow && other);
        
        virtual ~RenderWindow();

        RenderWindow & operator=(RenderWindow const &) = delete;

        RenderWindow & operator=(RenderWindow && other);

        void run();

    private:
        GLFWwindow * window = nullptr;

        std::unique_ptr<RenderContext> context = nullptr;

        // Called before the render loop.
        virtual void init();

        // Called once per loop of the render loop.
        virtual void render(double elapsedTime);
    };
}