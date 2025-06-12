/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationPistolFire]
Description : [This class holds data/functions for playing pistol fire animation for player chatacter]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cAnimationPistolFire.h"

cAnimationPistolFire::cAnimationPistolFire()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mPlayerShootSheetTex)
{
	mTotalFrames = sf::Vector2u(1, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.05f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);

	// Init sprite rect at first frame
	mSpriteRect.position = (sf::Vector2i(0, 0));
	mSpriteRect.size = mFrameSize;
	mSprite.setTextureRect(mSpriteRect);
}
