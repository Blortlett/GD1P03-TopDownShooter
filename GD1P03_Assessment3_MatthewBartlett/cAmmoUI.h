/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAmmoUI]
Description : [This class holds funtionality to draw/display ammo count UI in game]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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