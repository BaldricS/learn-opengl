#include "ogl/uniforms/Mat4.h"

#include <glad/glad.h>

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ogl::uniforms
{
    void Mat4::set(glm::mat4 const & m)
    {
        glUniformMatrix4fv(get_location(), 1, GL_FALSE, glm::value_ptr(m));
    }
}