#include "cAnimationBase.h"
#include <iostream>

cAnimationBase::cAnimationBase(sf::Texture* _SpriteSheetTex)
	: mSprite(*_SpriteSheetTex)
{
    // Init sprite rect at first frame
    /*mSpriteRect.position = (sf::Vector2i(0, 0));
    mSpriteRect.size = mFrameSize;
    mSprite.setTextureRect(mSpriteRect);*/
}

void cAnimationBase::Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds)
{
    // Accumulate time
    mAnimationTime += _DeltaSeconds;

    // Set sprite position
    mSprite.setPosition(_ObjectPosition);

    // No need to animate 0 frames - Division by 0 anywayz
    if (mTotalFrames.x == 0) return;

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        mAnimationTime -= mFrameDuration;  // Reset timer
        mCurrentFrame.x = (mCurrentFrame.x + 1) % mTotalFrames.x;  // Cycle through frames

        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;

        // Update sprite rectangle
        mSprite.setTextureRect(mSpriteRect);
    }
}

void cAnimationBase::Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds, bool& _AnimationComplete)
{
    mAnimationTime += _DeltaSeconds;
    mSprite.setPosition(_ObjectPosition);

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        std::cout << "PistolFireFrame" << std::endl;

        // calc new sprite rectangle
        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;
        // Update sprite rectangle
        mSprite.setTextureRect(mSpriteRect);

        mAnimationTime -= mFrameDuration;  // Reset timer
        
        // check for animation complete
        if (mCurrentFrame.x >= mTotalFrames.x)
        {
            std::cout << "PistolFireComplete!" << std::endl;
            mCurrentFrame.x = 0;
            _AnimationComplete = true;
        }
        else 
        {
            // Increment frame
            mCurrentFrame.x += 1;
        }
    }
}

void cAnimationBase::Draw(sf::RenderWindow& _RenderWindow)
{
    _RenderWindow.draw(mSprite);
}

void cAnimationBase::RotateAnimation(sf::Angle _Rotation)
{
    mSprite.setRotation(_Rotation);
}

void cAnimationBase::RestartAnimation()
{
    mCurrentFrame = sf::Vector2u(0, 0);
}

sf::Angle cAnimationBase::GetRotation()
{
    return mSprite.getRotation();
}
