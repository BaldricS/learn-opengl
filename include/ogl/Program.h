#pragma once

namespace ogl
{
    class Shader;
    
    class Program
    {
    public:
        Program();

        Program(Program const &) = delete;

        Program(Program && other);

        ~Program();

        Program & operator=(Program const &) = delete;

        Program & operator=(Program && other);

        void add_shader(Shader const & shader);

        unsigned int handle() const;

        void link();

    private:
        unsigned int program;
    };
}