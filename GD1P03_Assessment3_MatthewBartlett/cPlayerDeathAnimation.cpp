#include "cPlayerDeathAnimation.h"

cPlayerDeathAnimation::cPlayerDeathAnimation()
    : cPlayerAnimationBase(cPlayerUtils::GetInstance().mPlayerDeathSheetTex)
{
    // Setup animation control variables
    mTotalFrames = sf::Vector2u(3, 1);
    mFrameSize = sf::Vector2i(48, 48);
    mFrameDuration = 0.2f;
    sf::Vector2f newOrigin = sf::Vector2f(mFrameSize.x / 2, mFrameSize.y / 2);
    mSprite.setOrigin(newOrigin);
}

void cPlayerDeathAnimation::Animate(sf::Vector2f _EnemyPosition, float _DeltaSeconds)
{
    // Only play animation once, then freeze at end. No need for rest of function if complete
    if (mCurrentFrame.x >= mTotalFrames.x - 1) return;

    // Accumulate time
    mAnimationTime += _DeltaSeconds;

    // Set sprite position
    mSprite.setPosition(_EnemyPosition);

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        mAnimationTime -= mFrameDuration;  // Reset timer
        mCurrentFrame.x = (mCurrentFrame.x + 1) % mTotalFrames.x;  // Cycle through frames

        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (1 + mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;

        // Update sprite rectangle
        mSprite.setTextureRect(mSpriteRect);
    }
}
