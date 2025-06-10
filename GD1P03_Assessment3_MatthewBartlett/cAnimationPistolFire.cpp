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
}

void cAnimationPistolFire::Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds)
{
    // Accumulate time
    mAnimationTime += _DeltaSeconds;
    // Set sprite position
    mSprite.setPosition(_PlayerPosition);

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        if (mTotalFrames.x == mTotalFrames.x)
        {
            mAnimationComplete = true;
        }
        mAnimationTime -= mFrameDuration;  // Reset timer
        mCurrentFrame.x = (mCurrentFrame.x + 1) % mTotalFrames.x;  // Cycle through frames

        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (1 + mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;

        // Update sprite rectangle
        mSprite.setTextureRect(mSpriteRect);
    }
}

bool cAnimationPistolFire::AnimationCallback()
{
    // Send back a true bool on animation complete.
    if (mAnimationComplete)
    {
        mAnimationComplete = false;
        return !mAnimationComplete;
    }
}
