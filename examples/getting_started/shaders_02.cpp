#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/shaders/Program.h>

#include <ogl/uniforms/Float.h>

#include <ogl/utils/MainMacro.h>
#include <ogl/utils/ProgramFactory.h>
#include <ogl/utils/ScopedBind.h>

#include <string>

std::string vertex_source = R"(
#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 color;

out vec4 ourColor;

uniform float hOffset = 0.0f;

void main()
{
    gl_Position = vec4(pos.x + hOffset, pos.y, pos.z, 1.0f);
    ourColor = color;
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
        prog(ogl::utils::createProgram(vertex_source, frag_source)),
        hOffset(prog, "hOffset")
    {
    }

private:
    ogl::Buffer triangle_data;
    ogl::VertexArray vao;

    ogl::shaders::Program prog;

    ogl::uniforms::Float hOffset; // Order dep with prog
    
    void init() override
    {
        ogl::utils::ScopedBind bind_vao(vao);
		ogl::utils::ScopedBind bind_buffer(triangle_data);
        triangle_data.load_data<float>({
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    void render(double elapsedTime) override
    {
        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        hOffset.set(static_cast<float>(std::sin(elapsedTime)));

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

RUN_PROGRAM(App)