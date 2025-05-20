#include <SFML/Graphics.hpp>

int main()
{
    // Create a fullscreen window at 1920x1080
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML works!", sf::Style::None);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            // Optional: Add escape key to exit fullscreen
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}