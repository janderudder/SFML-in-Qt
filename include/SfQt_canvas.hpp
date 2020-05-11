#pragma once
#include "ISfQt_canvas.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>
#include <functional>


class SfQt_canvas
    : public ISfQt_canvas
{
    std::function<void()>            m_init_function;
    std::function<void()>            m_update_function;

public:
    using Parent   = QWidget*;
    using Position = QPoint;
    using Size     = QSize;

public:
    template <class Init_fn, class Update_fn>
    SfQt_canvas(
        Parent          parent,
        Position const& position,
        Size const&     size,
        Init_fn&&,
        Update_fn&&
    ) noexcept;

    void on_init() override;
    void on_update() override;

};




// inline impl.
template <class Init_fn, class Update_fn>
SfQt_canvas::SfQt_canvas(
    QWidget*            parent,
    QPoint const&       position,
    QSize const&        size,
    Init_fn&&           init_fn,
    Update_fn&&         update_fn
) noexcept
    : ISfQt_canvas      {parent, position, size}
    , m_init_function   {std::forward<Init_fn>(init_fn)}
    , m_update_function {std::forward<Update_fn>(update_fn)}
{
}
