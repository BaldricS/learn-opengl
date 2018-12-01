#include "ogl/RenderWindow.h"

#include "private/RenderContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <utility>

namespace
{
    void framebuffer_size_callback(GLFWwindow *, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}

namespace ogl
{
    RenderWindow::RenderWindow(int majorVersion, int minorVersion, int width, int height) :
        context(new RenderContext(majorVersion, minorVersion))
    {
        window = glfwCreateWindow(width, height, "Render Window", NULL, NULL);
        if (window == nullptr)
        {
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, width, height);

        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    }

    RenderWindow::RenderWindow(RenderWindow && other) :
        window(std::exchange(other.window, nullptr)),
        context(std::exchange(other.context, nullptr))
    {
    }

    RenderWindow::~RenderWindow() = default;

    RenderWindow & RenderWindow::operator=(RenderWindow && other)
    {
        window = std::exchange(other.window, nullptr);
        context = std::exchange(other.context, nullptr);

        return *this;
    }

    void RenderWindow::run()
    {
        init();

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            render();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void RenderWindow::init()
    {
        // no-op
    }

    void RenderWindow::render()
    {
        // no-op
    }
}