#include "cAnimationLegsEnemyRun.h"

cAnimationLegsEnemyRun::cAnimationLegsEnemyRun()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mEnemyLegsRun)
{
	mTotalFrames = sf::Vector2u(5, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);
}

void cAnimationLegsEnemyRun::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{
	cAnimationBase::Animate(_PlayerPosition, _DeltaSeconds);
}