#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/Program.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/textures/Texture.h>
#include <ogl/textures/TextureUniform.h>

#include <ogl/utils/MainMacro.h>
#include <ogl/utils/ProgramFactory.h>
#include <ogl/utils/ScopedBind.h>

#include <memory>
#include <string>

std::string vertex_source = R"(
#version 330 core

layout (location = 0) in vec4 pos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 uvs;

out vec2 tex_coords;
out vec4 vert_color;

void main()
{
    gl_Position = pos;
    tex_coords = uvs;
    vert_color = color;
})";

std::string frag_source = R"(
#version 330 core

out vec4 FragColor;

in vec4 vert_color;
in vec2 tex_coords;

uniform sampler2D container;
uniform sampler2D awesome;

void main()
{
    FragColor = mix(texture(container, tex_coords), texture(awesome, tex_coords), 0.2) * vert_color;
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        prog(ogl::utils::createProgram(vertex_source, frag_source)),
        indices(ogl::BufferType::ElementArrayBuffer),
        container(),
        awesomeface(),
        container_uniform(nullptr),
        awesome_uniform(nullptr)
    {
        container.load_data("./resources/textures/container.jpg");
        awesomeface.load_data("./resources/textures/awesomeface.png");

        container_uniform.reset(new ogl::textures::TextureUniform(prog, "container", container, 0));
        awesome_uniform.reset(new ogl::textures::TextureUniform(prog, "awesome", awesomeface, 1));
    }

private:
    ogl::Buffer triangle_data;
    ogl::Buffer indices;
    ogl::Program prog;
    ogl::VertexArray vao;

    ogl::textures::Texture container;
    ogl::textures::Texture awesomeface;

    std::unique_ptr<ogl::textures::TextureUniform> container_uniform;
    std::unique_ptr<ogl::textures::TextureUniform> awesome_uniform;
    
    void init() override
    {
        vao.bind();

		ogl::utils::ScopedBind bind_buffer(triangle_data);
        triangle_data.load_data<float>({
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        ogl::utils::ScopedBind bind_element(indices);        
        indices.load_data<unsigned int>({
            0, 1, 3,
            1, 2, 3
        });

        // VAO needs to be unbound before an element array buffer is unbound.
        // This means we can't use our fancy ScopedBind util. Oh well.
        vao.unbind();

        ogl::utils::ScopedBind bind_progam(prog);
        container_uniform->set();
        awesome_uniform->set();
    }

    void render(double) override
    {
        ogl::utils::ScopedBind bind_container(*container_uniform);
        ogl::utils::ScopedBind bind_awesome(*awesome_uniform);

        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
};

RUN_PROGRAM(App)