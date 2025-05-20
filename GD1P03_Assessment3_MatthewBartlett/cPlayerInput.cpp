/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerInput]
Description : [This class has functions to easily read inputs from the player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cPlayerInput.h"
#include <iostream>

cPlayerInput::cPlayerInput()
{
}

bool cPlayerInput::IsSpacebarInputPressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
}

bool cPlayerInput::IsMoveUpInputPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
}

bool cPlayerInput::IsMoveDownInputPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S));
}

bool cPlayerInput::IsMoveLeftInputPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
}

bool cPlayerInput::IsMoveRightInputPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D));
}

bool cPlayerInput::IsLeftClickPressed() const
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

bool cPlayerInput::IsRightClickPressed() const
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
}

bool cPlayerInput::IsPauseButtonPressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
}

bool cPlayerInput::IsDebugButtonPressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Grave);
}

sf::Vector2i cPlayerInput::GetMousePosition(sf::RenderWindow& window) const
{
    return sf::Mouse::getPosition(window);
}
