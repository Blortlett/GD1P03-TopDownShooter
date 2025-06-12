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

#include "cAmmoUI.h"
#include "cSharedUtils.h"

cAmmoUI::cAmmoUI(sf::RenderWindow& _Window)
	: mGameWindow(_Window)
	, mBulletFullSpriteList() // Init empty vectors
	, mBulletEmptySpriteList()
{
	// Get UI textures
	sf::Texture& fullTexture = cSharedUtils::GetInstance().mUIBulletFullTex;
	sf::Texture& emptyTexture = cSharedUtils::GetInstance().mUIBulletEmptyTex;
	
	mBulletFullSpriteList.reserve(mMaxBulletCount);
	mBulletEmptySpriteList.reserve(mMaxBulletCount);

	// Setup bullet sprites
	for (int i = 0; i < mMaxBulletCount; ++i) {
		sf::Sprite fullSprite(fullTexture); // Construct sprite with texture
		fullSprite.setPosition({ (i * 22.0f) + 110.f, 1015.f });  // Bottom left of screen
		fullSprite.setScale({ 2.f, 2.f });
		fullSprite.setOrigin({0.f , fullSprite.getGlobalBounds().size.y});
		mBulletFullSpriteList.push_back(fullSprite);

		sf::Sprite emptySprite(emptyTexture); // Construct sprite with texture
		emptySprite.setPosition({ (i * 22.0f) + 110, 1015.f }); // Bottom left of screen
		emptySprite.setScale({ 2.f, 2.f });
		emptySprite.setOrigin({ 0.f , emptySprite.getGlobalBounds().size.y });
		mBulletEmptySpriteList.push_back(emptySprite);
	}

	// Setup Background rect
	mBackgroundPanel.setSize({320.f , 75.f});
	mBackgroundPanel.setOrigin({0.f , 75.f });
	mBackgroundPanel.setFillColor(sf::Color(11, 11, 11, 150));
	mBackgroundPanel.setPosition({75.f , 1010.f });
}

void cAmmoUI::Draw()
{
	// Draw Background
	mGameWindow.draw(mBackgroundPanel);
	for (int i = 0; i < mMaxBulletCount; ++i) 
	{
		// Draw bullet slots
		if (i <= mActiveBulletCount)
			mGameWindow.draw(mBulletFullSpriteList[i]);
		else
			mGameWindow.draw(mBulletEmptySpriteList[i]);
	}
}

void cAmmoUI::SetBulletCount(int _BulletCount)
{
	mActiveBulletCount = _BulletCount;
}
