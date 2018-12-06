#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/shaders/Program.h>
#include <ogl/shaders/Shader.h>
#include <ogl/shaders/ShaderType.h>

#include <ogl/utils/MainMacro.h>
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

std::string frag_yellow_src = R"(
#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        indices(ogl::BufferType::ElementArrayBuffer)
    {
        ogl::shaders::Shader vertex(ogl::shaders::ShaderType::Vertex, vertex_source);
        ogl::shaders::Shader frag_orange(ogl::shaders::ShaderType::Fragment, frag_source);
        ogl::shaders::Shader frag_yellow(ogl::shaders::ShaderType::Fragment, frag_yellow_src);

        prog_orange.add_shader(frag_orange);
        prog_orange.add_shader(vertex);
        prog_orange.link();

        prog_yellow.add_shader(vertex);
        prog_yellow.add_shader(frag_yellow);
        prog_yellow.link();
    }

private:
    ogl::Buffer triangle_data;
    ogl::Buffer indices;
    ogl::VertexArray vao;

    ogl::shaders::Program prog_orange;
    ogl::shaders::Program prog_yellow;
    
    void init() override
    {
        vao.bind();

		ogl::utils::ScopedBind bind_buffer(triangle_data);
        triangle_data.load_data<float>({
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        ogl::utils::ScopedBind bind_element(indices);        
        indices.load_data<unsigned int>({
            0, 1, 3,
            1, 2, 3
        });

        // VAO needs to be unbound before an element array buffer is unbound.
        // This means we can't use our fancy ScopedBind util. Oh well.
        vao.unbind();
    }

    void render(double) override
    {
        ogl::utils::ScopedBind bind_vao(vao);

        prog_orange.bind();

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        prog_yellow.bind();

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void *)(3 * sizeof(unsigned int)));
    }
};

RUN_PROGRAM(App)