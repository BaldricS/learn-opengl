#include "ogl/uniforms/Float.h"

namespace ogl::uniforms
{
    void Float::set(float v0)
    {
        glUniform1f(get_location(), v0);
    }
}