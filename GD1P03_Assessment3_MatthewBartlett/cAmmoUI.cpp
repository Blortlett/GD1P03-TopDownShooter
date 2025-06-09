#include "cAmmoUI.h"
#include "cSharedUtils.h"

cAmmoUI::cAmmoUI(sf::RenderWindow _Window)
	: mGameWindow(_Window)
	, mBulletFullSpriteList() // Init empty vectors
	, mBulletEmptySpriteList()
{
	// Get UI textures
	sf::Texture& fullTexture = cSharedUtils::GetInstance().mUIBulletFullTex;
	sf::Texture& emptyTexture = cSharedUtils::GetInstance().mUIBulletEmptyTex;
	
	mBulletFullSpriteList.reserve(mMaxBulletCount + 1);
	mBulletEmptySpriteList.reserve(mMaxBulletCount + 1);

	for (int i = 0; i < 12; ++i) {
		sf::Sprite fullSprite(fullTexture); // Construct sprite with texture
		fullSprite.setPosition({ (i * 50.0f) + 50, 1080.f }); // Example positioning
		mBulletFullSpriteList.push_back(fullSprite);

		sf::Sprite emptySprite(emptyTexture); // Construct sprite with texture
		emptySprite.setPosition({ (i * 50.0f) + 50, 1080.f }); // Bottom left of screen
		mBulletEmptySpriteList.push_back(emptySprite);
	}
}

void cAmmoUI::Draw()
{
	mGameWindow.draw(mBackgroundPanel);
	for (int i = 0; i < mMaxBulletCount; ++i) 
	{

		if (i <= mActiveBulletCount)
			mGameWindow.draw(mBulletFullSpriteList[i]);
		else
			mGameWindow.draw(mBulletEmptySpriteList[i]);
	}
}

void cAmmoUI::SetBulletCount(int _BulletCount)
{
}
