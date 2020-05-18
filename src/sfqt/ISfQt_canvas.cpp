#include "sfqt/ISfQt_canvas.hpp"


#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif




ISfQt_canvas::ISfQt_canvas(
      QWidget*      parent
    , QPoint const& position
    , QSize const&  size
    , unsigned int  frame_time
) noexcept
    : QWidget   {parent}
    , m_is_init {false}
{
    // Setup some states to allow direct rendering into the widget
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(position);
    resize(size);

    m_timer.setInterval(frame_time);
}




void ISfQt_canvas::showEvent(QShowEvent*)
{
    if (!m_is_init)
    {
        // Under X11, we need to flush the commands sent to the server to ensure
        // that SFML will get an updated view of the windows
        #ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif

        // Create the SFML window with the widget handle
        sf::RenderWindow::create(sf::WindowHandle(winId()));

        // Let the derived class do its specific stuff
        this->on_init();

        // Setup the timer to trigger a refresh at specified framerate
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));
        m_timer.start();
        m_is_init = true;
    }
}




QPaintEngine* ISfQt_canvas::paintEngine() const
{
    return nullptr;
}




void ISfQt_canvas::paintEvent(QPaintEvent*)
{
    while (this->pollEvent(m_event)) {}
    this->on_update();
}
