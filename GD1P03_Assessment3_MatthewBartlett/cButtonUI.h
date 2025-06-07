/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cButtonUI]
Description : [cButtonUI is the base class for all buttons in this project]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class cButtonUI {
protected:
    sf::RectangleShape mButtonShape;
    sf::Color mDefaultColor = sf::Color(100, 100, 100);
    sf::Color mHoverColor = sf::Color(180, 180, 180);
    sf::Color mClickColor = sf::Color(80, 80, 80);
    bool isPressed;
    bool isHovered;
    sf::Vector2f mPosition;
    sf::Vector2f mSize;

public:
    cButtonUI(sf::Vector2f position, sf::Vector2f size);
    virtual ~cButtonUI() = default;
    bool IsMouseOver(sf::RenderWindow& window);
    bool IsButtonClicked();
    void Update(sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);

    virtual void OnButtonClick() = 0;

    // Getters
    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();

    // Setters
    void SetPosition(sf::Vector2f position);
    void SetSize(sf::Vector2f size);
};