#include "sfqt/SfQt_canvas.hpp"


// inherited from ISfQt_canvas
////////////////////////////////////////////////////////////////////////////////
void SfQt_canvas::on_init()
{
    std::invoke(m_init_function);
}




void SfQt_canvas::on_update()
{
    std::invoke(m_update_function);
}




// setters
////////////////////////////////////////////////////////////////////////////////
std::function<void()> const& SfQt_canvas::init_fn() const
{
    return m_init_function;
}




std::function<void()> const& SfQt_canvas::update_fn() const
{
    return m_update_function;
}
