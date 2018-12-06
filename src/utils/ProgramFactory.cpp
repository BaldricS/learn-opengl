#include "ogl/utils/ProgramFactory.h"

#include "ogl/shaders/Shader.h"

namespace ogl::utils
{
    shaders::Program createProgram(std::string const & vertexSrc, std::string const & fragmentSrc)
    {
        shaders::Shader vertex(shaders::ShaderType::Vertex, vertexSrc);
        shaders::Shader fragment(shaders::ShaderType::Fragment, fragmentSrc);

        shaders::Program program;
        program.add_shader(vertex);
        program.add_shader(fragment);
        program.link();

        return program;
    }    
}