#include "cAnimationPistolIdle.h"

cAnimationPistolIdle::cAnimationPistolIdle()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mPlayerIdleSheet)
{
	mTotalFrames = sf::Vector2u(4, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
}

void cAnimationPistolIdle::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{

}