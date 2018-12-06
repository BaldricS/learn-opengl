#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/shaders/Program.h>

#include <ogl/textures/Texture.h>
#include <ogl/textures/TextureUnit.h>

#include <ogl/uniforms/Sampler2D.h>

#include <ogl/utils/MainMacro.h>
#include <ogl/utils/ProgramFactory.h>
#include <ogl/utils/ScopedBind.h>

#include <string>

std::string vertex_source = R"(
#version 330 core

layout (location = 0) in vec4 pos;
layout (location = 1) in vec2 uvs;

out vec2 tex_coords;

void main()
{
    gl_Position = pos;
    tex_coords = uvs;
})";

std::string frag_source = R"(
#version 330 core

out vec4 FragColor;

in vec2 tex_coords;

uniform sampler2D container;
uniform sampler2D awesome;

void main()
{
    vec4 texel = texture(awesome, vec2(1.0 - tex_coords.x, tex_coords.y));
    FragColor = mix(texture(container, tex_coords), texel, 0.2);
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        indices(ogl::BufferType::ElementArrayBuffer),
        prog(ogl::utils::createProgram(vertex_source, frag_source)),
        container(),
        awesomeface(),
        container_sampler(prog, "container"),
        awesome_sampler(prog, "awesome"),
        container_unit(container, 0),
        awesome_unit(awesomeface, 1)
    {
        container.load_data("./resources/textures/container.jpg");
        awesomeface.load_data("./resources/textures/awesomeface.png");
    }

private:
    ogl::Buffer triangle_data;
    ogl::Buffer indices;
    ogl::VertexArray vao;

    ogl::shaders::Program prog;

    // Order dependencies.
    ogl::textures::Texture container;
    ogl::textures::Texture awesomeface;

    ogl::uniforms::Sampler2D container_sampler;
    ogl::uniforms::Sampler2D awesome_sampler;

    ogl::textures::TextureUnit container_unit;
    ogl::textures::TextureUnit awesome_unit;
    
    void init() override
    {
        vao.bind();

		ogl::utils::ScopedBind bind_buffer(triangle_data);
        triangle_data.load_data<float>({
            0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        ogl::utils::ScopedBind bind_element(indices);        
        indices.load_data<unsigned int>({
            0, 1, 3,
            1, 2, 3
        });

        // VAO needs to be unbound before an element array buffer is unbound.
        // This means we can't use our fancy ScopedBind util. Oh well.
        vao.unbind();

        ogl::utils::ScopedBind bind_progam(prog);
        container_sampler.set(container_unit);
        awesome_sampler.set(awesome_unit);
    }

    void render(double) override
    {
        ogl::utils::ScopedBind bind_container(container_unit);
        ogl::utils::ScopedBind bind_awesome(awesome_unit);

        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
};

RUN_PROGRAM(App)