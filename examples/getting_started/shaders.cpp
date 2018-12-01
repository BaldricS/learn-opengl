#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/Program.h>
#include <ogl/RenderWindow.h>
#include <ogl/Uniform.h>
#include <ogl/VertexArray.h>

#include <ogl/utils/MainMacro.h>
#include <ogl/utils/ProgramFactory.h>
#include <ogl/utils/ScopedBind.h>

#include <string>

std::string vertex_source = R"(
#version 330 core

layout (location = 0) in vec4 pos;

void main()
{
    gl_Position = pos;
})";

std::string frag_source = R"(
#version 330 core

out vec4 FragColor;

uniform vec4 ourColor;

void main()
{
    FragColor = ourColor;
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        prog(ogl::utils::createProgram(vertex_source, frag_source)),
        color(prog, "ourColor")
    {
    }

private:
    ogl::Buffer triangle_data;
    ogl::Program prog;
    ogl::Uniform<float, 4> color; // Order dependency with prog
    ogl::VertexArray vao;
    
    void init() override
    {
        ogl::utils::ScopedBind bind_vao(vao);
		ogl::utils::ScopedBind bind_buffer(triangle_data);
        triangle_data.load_data<float>({
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }

    void render(double elapsedTime) override
    {
        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        double const greenValue = std::sin(elapsedTime) / 2.0 + 0.5;

        color.set(0.0f, static_cast<float>(greenValue), 0.0f, 1.0f);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

RUN_PROGRAM(App)