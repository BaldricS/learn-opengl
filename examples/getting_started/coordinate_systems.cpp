#include <glad/glad.h>

#include <ogl/Buffer.h>
#include <ogl/RenderWindow.h>
#include <ogl/VertexArray.h>

#include <ogl/shaders/Program.h>

#include <ogl/textures/Texture.h>
#include <ogl/textures/TextureUnit.h>

#include <ogl/uniforms/Mat4.h>
#include <ogl/uniforms/Sampler2D.h>

#include <ogl/utils/MainMacro.h>
#include <ogl/utils/ProgramFactory.h>
#include <ogl/utils/ScopedBind.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

std::string vertex_source = R"(
#version 330 core

layout (location = 0) in vec4 pos;
layout (location = 1) in vec2 uvs;

out vec2 tex_coords;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * pos;
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
    FragColor = mix(texture(container, tex_coords), texture(awesome, tex_coords), 0.2);
})";

class App : public ogl::RenderWindow
{
public:
    App() :
        prog(ogl::utils::createProgram(vertex_source, frag_source)),
        container(),
        awesomeface(),
        transform_uniform(prog, "mvp"),
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
    ogl::VertexArray vao;

    ogl::shaders::Program prog;

    ogl::textures::Texture container;
    ogl::textures::Texture awesomeface;

    ogl::uniforms::Mat4 transform_uniform;
    ogl::uniforms::Sampler2D container_sampler;
    ogl::uniforms::Sampler2D awesome_sampler;

    ogl::textures::TextureUnit container_unit;
    ogl::textures::TextureUnit awesome_unit;
    
    void init() override
    {
        ogl::utils::ScopedBind bind_vao(vao);
		ogl::utils::ScopedBind bind_buffer(triangle_data);

        triangle_data.load_data<float>({
             -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        });

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        ogl::utils::ScopedBind bind_progam(prog);
        container_sampler.set(container_unit);
        awesome_sampler.set(awesome_unit);
    }

    void render(double elapsedTime) override
    {
        ogl::utils::ScopedBind bind_container(container_unit);
        ogl::utils::ScopedBind bind_awesome(awesome_unit);

        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        glm::mat4 model(1.0f);
        model = glm::rotate(model, static_cast<float>(elapsedTime) * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

        glm::mat4 view(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        glm::mat4 projection(1.0f);
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        transform_uniform.set(projection * view * model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
};

RUN_PROGRAM(App)