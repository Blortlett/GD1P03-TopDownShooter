/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationPistolIdle]
Description : [This class holds data/functions for playing pistol idle animation for player chatacter]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cAnimationPistolIdle.h"

cAnimationPistolIdle::cAnimationPistolIdle()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mPlayerIdleSheetTex)
{
	mTotalFrames = sf::Vector2u(3, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);
}

void cAnimationPistolIdle::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{
	cAnimationBase::Animate(_PlayerPosition, _DeltaSeconds);
}