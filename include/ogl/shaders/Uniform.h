#pragma once

#include <glad/glad.h>

namespace ogl
{
        void set(float x, float y, float z, float w)
        {
            glUniform4f(0, x, y, z, w);
        }

        void set(float x)
        {
            glUniform1f(0, x);
        }

        void set(int v0)
        {
            glUniform1i(0, v0);
        }
}