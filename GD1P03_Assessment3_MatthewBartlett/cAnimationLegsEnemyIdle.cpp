/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationLegsEnemyIdle]
Description : [This class holds enemy legs idle animation data/functions]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cAnimationLegsEnemyIdle.h"

cAnimationLegsEnemyIdle::cAnimationLegsEnemyIdle()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mEnemyLegsIdle)
{
	mTotalFrames = sf::Vector2u(0, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);
}

void cAnimationLegsEnemyIdle::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{
	cAnimationBase::Animate(_PlayerPosition, _DeltaSeconds);
}