#pragma once
#include "sfqt/ISfQt_canvas.hpp"
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
    SfQt_canvas(
        Parent          parent      = nullptr,
        Position const& position    = {},
        Size const&     size        = {}
    ) noexcept;

    template <class Init_fn, class Update_fn>
    SfQt_canvas(
        Parent          parent,
        Position const& position,
        Size const&     size,
        Init_fn&&       on_init_fn,
        Update_fn&&     on_update_fn
    ) noexcept;

    void on_init() override;
    void on_update() override;

    template <class Fn> void set_init_fn(Fn&&);
    template <class Fn> void set_update_fn(Fn&&);

    auto init_fn() const -> std::function<void()> const&;
    auto update_fn() const -> std::function<void()> const&;

};




// inline impl.
////////////////////////////////////////////////////////////////////////////////
template <class Init_fn, class Update_fn>
SfQt_canvas::SfQt_canvas(
    QWidget*            parent,
    QPoint const&       position,
    QSize const&        size,
    Init_fn&&           on_init_fn,
    Update_fn&&         on_update_fn
) noexcept
    : ISfQt_canvas      {parent, position, size}
    , m_init_function   {std::forward<Init_fn>(on_init_fn)}
    , m_update_function {std::forward<Update_fn>(on_update_fn)}
{
}




template <class Fn>
void SfQt_canvas::set_init_fn(Fn&& fn)
{
    m_init_function = std::forward<Fn>(fn);
}




template <class Fn>
void SfQt_canvas::set_update_fn(Fn&& fn)
{
    m_update_function = std::forward<Fn>(fn);
}
