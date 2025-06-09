#pragma once
#include <SFML/Graphics.hpp>

class cAmmoUI
{
private:
	// UI Elements
	sf::RectangleShape mBackgroundPanel;
	std::vector<sf::Sprite> mBulletFullSpriteList;
	std::vector<sf::Sprite> mBulletEmptySpriteList;

	int mMaxBulletCount = 12;
	int mActiveBulletCount = 0;

	// WindowRef
	sf::RenderWindow& mGameWindow;
public:
	cAmmoUI(sf::RenderWindow& _Window);

	void Draw();

	void SetBulletCount(int _BulletCount);
};