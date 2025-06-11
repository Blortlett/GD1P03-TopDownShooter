#pragma once
#include "cButtonUI.h"

class cGameStateManager;
class cPauseMenu;

class cResumeButton : public cButtonUI
{
public:
	cResumeButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

class cOptionsButton : public cButtonUI
{
public:
	cOptionsButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Returns to main menu
class cQuitGameButton : public cButtonUI
{
public:
	cQuitGameButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu, cGameStateManager& _GameStateManager);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	cGameStateManager& mGameStateManager;

	sf::Font& mBodyFont;
	sf::Text mText;
};

class cDebugMenuButton : public cButtonUI
{
public:
	cDebugMenuButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};