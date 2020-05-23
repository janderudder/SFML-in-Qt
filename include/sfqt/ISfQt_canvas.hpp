#pragma once
#include <QWidget>
#include <QTimer>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


class ISfQt_canvas
    : public QWidget
    , protected sf::RenderWindow
{
    Q_OBJECT

public:
    ISfQt_canvas(
        QWidget*        parent      = nullptr,
        QPoint const&   position    = {},
        QSize const&    size        = {},
        unsigned int    frame_time  = 15
    ) noexcept;

    virtual ~ISfQt_canvas() {};

    virtual void on_init() = 0;
    virtual void on_update() = 0;

    // inherited from QWidget
    auto paintEngine() const -> QPaintEngine* override;
    void showEvent(QShowEvent*) override;
    void paintEvent(QPaintEvent*) override;

    // pull protected methods in public scope
    using sf::RenderWindow::clear;
    using sf::RenderWindow::display;
    using sf::RenderWindow::draw;
    using sf::RenderWindow::pollEvent;
    using sf::RenderWindow::waitEvent;

private:
    QTimer    m_timer;
    bool      m_is_init;

};
