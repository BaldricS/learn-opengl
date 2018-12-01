#pragma once

namespace ogl::utils
{
    template<typename Bindable>
    class ScopedBind
    {
    public:
        ScopedBind(Bindable & bindable_) :
            bindable(bindable_)
        {
            bindable.bind();
        }

        ~ScopedBind()
        {
            bindable.unbind();
        }
    
    private:
        Bindable & bindable;
    }
}