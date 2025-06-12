/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationLegsEnemyRun]
Description : [This class holds animation data for enemy legs running state]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/


#include "cAnimationLegsEnemyRun.h"

cAnimationLegsEnemyRun::cAnimationLegsEnemyRun()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mEnemyLegsRun)
{
	mTotalFrames = sf::Vector2u(5, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);

	// Init sprite rect at first frame
	mSpriteRect.position = (sf::Vector2i(0, 0));
	mSpriteRect.size = mFrameSize;
	mSprite.setTextureRect(mSpriteRect);
}

void cAnimationLegsEnemyRun::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{
	cAnimationBase::Animate(_PlayerPosition, _DeltaSeconds);
}