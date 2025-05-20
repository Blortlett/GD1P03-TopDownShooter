#include "cAnimationBase.h"

cAnimationBase::cAnimationBase(sf::Sprite _SpriteSheet)
	: mSprite(_SpriteSheet)
{
}

void cAnimationBase::LoadSpriteSheet(std::string filePath)
{
}

void cAnimationBase::Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds)
{
    // Accumulate time
    mAnimationTime += _DeltaSeconds;

    // Set sprite position
    mSprite.setPosition(_ObjectPosition);

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

void cAnimationBase::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(mSprite);
}
