#include "ogl/RenderWindow.h"

#include "private/RenderContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

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
        window = glfwCreateWindow(width, height, "Render Window", nullptr, nullptr);
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

    RenderWindow::~RenderWindow() = default;

    void RenderWindow::run() const
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwSwapBuffers(window);
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
}