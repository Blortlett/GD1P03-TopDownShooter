#include "cAnimationPistolFire.h"
#include "cCharacter.h"

cAnimationPistolFire::cAnimationPistolFire(cCharacter& _OwnerCharacter)
	: cPlayerAnimationBase(cPlayerUtils::GetInstance().mPlayerShootSheetTex)
	, mOwnerCharacter(_OwnerCharacter)
{
	mTotalFrames = sf::Vector2u(1, 1);
	mFrameSize = sf::Vector2i(48, 48);
	mFrameDuration = 0.13f;
	sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
	mSprite.setOrigin(newOrigin);

	// Init sprite rect at first frame
	mSpriteRect.position = (sf::Vector2i(0, 0));
	mSpriteRect.size = mFrameSize;
	mSprite.setTextureRect(mSpriteRect);
}
