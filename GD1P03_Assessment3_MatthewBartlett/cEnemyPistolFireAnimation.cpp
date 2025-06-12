/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemyPistolFire]
Description : [This class stores data/functionality to animate enemy pistol fire]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cEnemyPistolFireAnimation.h"

cEnemyPistolFireAnimation::cEnemyPistolFireAnimation()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mEnemyShootSheetTex)
{
	mTotalFrames = sf::Vector2u(1, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.15f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);

	// Init sprite rect at first frame
	mSpriteRect.position = (sf::Vector2i(0, 0));
	mSpriteRect.size = mFrameSize;
	mSprite.setTextureRect(mSpriteRect);
}
