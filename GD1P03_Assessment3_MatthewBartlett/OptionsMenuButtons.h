#pragma once
#include "cButtonUI.h"

class cOptionsMenuUI;

// Mutes Game SFX
class cMuteSFX : public cButtonUI
{
public:
	cMuteSFX(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cOptionsMenuUI& mOptionsMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Mutes Game Music
class cMuteMusic : public cButtonUI
{
public:
	cMuteMusic(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cOptionsMenuUI& mOptionsMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Enable / Disable VSync
class cVSyncButton : public cButtonUI
{
public:
	cVSyncButton(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cOptionsMenuUI& mOptionsMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Returns to Pause Menu
class cBackButton : public cButtonUI
{
public:
	cBackButton(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cOptionsMenuUI& mOptionsMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};