#include "ogl/utils/ProgramFactory.h"

#include "ogl/Shader.h"

namespace ogl::utils
{
    Program createProgram(std::string const & vertexSrc, std::string const & fragmentSrc)
    {
        Shader vertex(ShaderType::Vertex, vertexSrc);
        Shader fragment(ShaderType::Fragment, fragmentSrc);

        Program program;
        program.add_shader(vertex);
        program.add_shader(fragment);
        program.link();

        return program;
    }    
}