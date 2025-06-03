#include "cEnemyIdleAnimation.h"

cEnemyIdleAnimation::cEnemyIdleAnimation()
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mEnemyIdleSheetTex)
{
	// Setup animation control variables
	mTotalFrames = sf::Vector2u(3, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);

	// Init sprite rect at first frame
	mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (1 + mCurrentFrame.x), 0));
	mSpriteRect.size = mFrameSize;
	mSprite.setTextureRect(mSpriteRect);
}

void cEnemyIdleAnimation::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{
	cAnimationBase::Animate(_PlayerPosition, _DeltaSeconds);
}
