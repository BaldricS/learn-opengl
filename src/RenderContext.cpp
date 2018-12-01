#include "private/RenderContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ogl
{
    RenderContext::RenderContext(int majorVersion, int minorVersion)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    RenderContext::~RenderContext()
    {
        glfwTerminate();
    }
}