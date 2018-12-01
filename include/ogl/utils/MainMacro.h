#pragma once

#include "ogl/RenderWindow.h"

#include <exception>
#include <iostream>
#include <memory>

#define RUN_PROGRAM(Window) \
int main() \
{ \
    try { \
        std::unique_ptr<ogl::RenderWindow> window(new Window()); \
        window->run(); \
        return 0; \
    } catch (std::exception const & e) { \
        std::cerr << "Error::" << e.what() << std::endl; \
    } \
}