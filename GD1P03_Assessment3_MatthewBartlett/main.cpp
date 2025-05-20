#include <SFML/Graphics.hpp>
#include "cApplicationManager.h"

int main()
{
    // Create a fullscreen window at 1920x1080
    //sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML works!", sf::Style::None);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    cApplicationManager ApplicationManager;
    ApplicationManager.Run();
}