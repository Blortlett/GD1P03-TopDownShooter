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
#include "cButtonUI.h"

// Constructor
cButtonUI::cButtonUI(sf::Vector2f position, sf::Vector2f size)
    : mPosition(position)
    , mSize(size)
    , isPressed(false)
    , isHovered(false)
{
    mButtonShape.setPosition(mPosition);
    mButtonShape.setSize(mSize);
    mButtonShape.setOrigin(mSize / 2.0f);

    mButtonShape.setFillColor(mDefaultColor);
    isPressed = false;
    isHovered = false;
}

// Is button hovered?
bool cButtonUI::IsMouseOver(sf::RenderWindow& window) {
    // Get mouse position in window coordinates
    sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
    // Convert to view coordinates
    sf::Vector2f mouseViewPos = window.mapPixelToCoords(mousePixelPos);

    if (mouseViewPos.x < mPosition.x - (mSize.x / 2) || mouseViewPos.x > mPosition.x + (mSize.x / 2)) {
        return false;
    }
    if (mouseViewPos.y < mPosition.y - (mSize.y / 2) || mouseViewPos.y > mPosition.y + (mSize.y / 2)) {
        return false;
    }
    return true;
}

// Is button clicked?
bool cButtonUI::IsButtonClicked() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

// Update Button
void cButtonUI::Update(sf::RenderWindow& window) {
    if (IsMouseOver(window)) {
        if (isPressed && !IsButtonClicked())
        {
            OnButtonClick();
        }
        isHovered = true;
        if (IsButtonClicked()) {
            mButtonShape.setFillColor(mClickColor);
            if (!isPressed)
            {
                isPressed = true;
                //OnButtonClick();
            }
        }
        else {
            mButtonShape.setFillColor(mHoverColor);
            isPressed = false;
        }
    }
    else {
        mButtonShape.setFillColor(mDefaultColor);
        isHovered = false;
        isPressed = false;
    }
}

// Draw the button
void cButtonUI::Draw(sf::RenderWindow& window) {
    window.draw(mButtonShape);
}



// get member variables
sf::Vector2f cButtonUI::GetPosition()
{
    return mPosition;
}
sf::Vector2f cButtonUI::GetSize()
{
    return mSize;
}

// Set member variables
void cButtonUI::SetPosition(sf::Vector2f position) {
    mPosition = position;
}
void cButtonUI::SetSize(sf::Vector2f size) {
    mSize = size;
}