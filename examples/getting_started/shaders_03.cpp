#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/Program.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/utils/MainMacro.h>
#include <ogl/utils/ProgramFactory.h>
#include <ogl/utils/ScopedBind.h>

#include <string>

std::string vertex_source = R"(
#version 330 core

layout (location = 0) in vec4 pos;

out vec4 ourColor;

void main()
{
    gl_Position = pos;
    ourColor = pos;
})";

std::string frag_source = R"(
#version 330 core

out vec4 FragColor;

in vec4 ourColor;

void main()
{
    FragColor = ourColor;
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        prog(ogl::utils::createProgram(vertex_source, frag_source))
    {
    }

private:
    ogl::Buffer triangle_data;
    ogl::Program prog;
    ogl::VertexArray vao;
    
    void init() override
    {
        ogl::utils::ScopedBind bind_vao(vao);
		ogl::utils::ScopedBind bind_buffer(triangle_data);
        triangle_data.load_data<float>({
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }

    void render(double) override
    {
        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

RUN_PROGRAM(App)