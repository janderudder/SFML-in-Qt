#include <QApplication>
#include <QFrame>
#include <SFML/Graphics.hpp>
#include "SfQt_canvas.hpp"


int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    // Create a frame for SFML to be displayed in
    auto main_frame = QFrame{};
    main_frame.setWindowTitle("SFML canvas in Qt window");
    main_frame.resize(320, 320);
    main_frame.show();

    // Objects that will be used by this specific SFML canvas
    sf::Texture cvs_tex;
    sf::Sprite cvs_sprite;
    sf::Clock cvs_clock;

    // An instance of a class that derives from ISfQt_canvas.
    // This class uses the constructor to provide on_init and on_update
    // handler functions as function objects, instead of implementing them
    // via inheritance.
    SfQt_canvas sfml_canvas
    {
        SfQt_canvas::Parent     {&main_frame},
        SfQt_canvas::Position   {32, 32},
        SfQt_canvas::Size       {256, 256},
        [&] // init function
        {
            cvs_tex.loadFromFile("resource/sfml-icon-small.png");
            cvs_sprite.setTexture(cvs_tex);
            auto const [l, t, w, h] = cvs_sprite.getLocalBounds();
            auto const sprite_center = sf::Vector2f{w, h} / 2.f;
            cvs_sprite.setPosition(sprite_center);
            cvs_sprite.setOrigin(sprite_center);
            cvs_clock.restart();
        },
        [&] // update function
        {
            sfml_canvas.clear(sf::Color::Black);
            cvs_sprite.rotate(cvs_clock.restart().asSeconds() * 150.f);
            sfml_canvas.draw(cvs_sprite);
        }
    };

    sfml_canvas.show();

    return app.exec();
}
