#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/shaders/Program.h>

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

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        prog(ogl::utils::createProgram(vertex_source, frag_source))
    {
    }

private:
    ogl::Buffer triangle_one;
    ogl::Buffer triangle_two;
    ogl::VertexArray vao_one;
    ogl::VertexArray vao_two;

    ogl::shaders::Program prog;

    void load_triangle(std::vector<float> const & data, ogl::VertexArray & vao, ogl::Buffer & buffer)
    {
        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_buff(buffer);

        buffer.load_data(data);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }
    
    void init() override
    {
        std::vector<float> const triangle_one_data {
            -0.8f, -0.8f, 0.0f,
            -0.4f, 0.6f, 0.0f,
            0.0f, -0.8f, 0.0f,
        };

        load_triangle(triangle_one_data, vao_one, triangle_one);

        std::vector<float> const triangle_two_data {
            0.0f, -0.8f, 0.0f,
            0.8f, -0.8f, 0.0f,
            0.4f, 0.6f, 0.0f,
        };

        load_triangle(triangle_two_data, vao_two, triangle_two);
    }

    void draw_triangles(ogl::VertexArray & vao)
    {
        ogl::utils::ScopedBind bind_vao(vao);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void render(double) override
    {
        ogl::utils::ScopedBind bind_program(prog);

        draw_triangles(vao_one);

        draw_triangles(vao_two);
    }
};

RUN_PROGRAM(App)