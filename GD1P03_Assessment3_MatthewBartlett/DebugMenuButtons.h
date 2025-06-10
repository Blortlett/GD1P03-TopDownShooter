#pragma once
#include "cButtonUI.h"

class cDebugMenuUI;

// Toggles Infinite Ammo
class cInfiniteAmmo : public cButtonUI
{
public:
	cInfiniteAmmo(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Toggles God Mode
class cGodMode : public cButtonUI
{
public:
	cGodMode(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Skips the current level
class cSkipLevel : public cButtonUI
{
public:
	cSkipLevel(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Returns to Pause Menu
class cBackFromDebugMenuButton : public cButtonUI
{
public:
	cBackFromDebugMenuButton(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};