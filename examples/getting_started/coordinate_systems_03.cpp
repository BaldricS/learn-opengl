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

#include <string>
#include <vector>

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

    void render(double elapsed) override
    {
        ogl::utils::ScopedBind bind_container(container_unit);
        ogl::utils::ScopedBind bind_awesome(awesome_unit);

        ogl::utils::ScopedBind bind_vao(vao);
        ogl::utils::ScopedBind bind_program(prog);

        static std::vector<glm::vec3> const cube_positions {
            { 0.0f, 0.0f, 0.0f },
            { 2.0f, 5.0f, -15.0f },
            { -1.5f, -2.2f, -2.5f },
            { -3.8f, -2.0f, -12.3f },
            { 2.4f, -0.4f, -3.5f },
            { -1.7f, 3.0f, -7.5f },
            { 1.3f, -2.0f, -2.5f },
            { 1.5f, 2.0f, -2.5f },
            { 1.5f, 0.2f, -1.5f },
            { -1.3f, 1.0f, -1.5f }
        };

        glm::mat4 view(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        glm::mat4 projection(1.0f);
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        for (std::size_t i = 0; i < cube_positions.size(); ++i)
        {
            float const angleDegrees = 20.0f * (i % 3 == 0 ? static_cast<float>(elapsed) : static_cast<float>(i));

            glm::mat4 model(1.0f);
            model = glm::translate(model, cube_positions[i]);

            model = glm::rotate(model, glm::radians(angleDegrees), glm::vec3(1.0f, 0.3f, 0.5f));

            transform_uniform.set(projection * view * model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
    }
};

RUN_PROGRAM(App)