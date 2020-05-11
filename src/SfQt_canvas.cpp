#include "SfQt_canvas.hpp"


void SfQt_canvas::on_init()
{
    std::invoke(m_init_function);
}




void SfQt_canvas::on_update()
{
    std::invoke(m_update_function);
}
