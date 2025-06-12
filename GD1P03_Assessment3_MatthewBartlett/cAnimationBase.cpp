/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationBase]
Description : [this class is the base class all playable animations classes inherit from]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cAnimationBase.h"
#include <iostream>

cAnimationBase::cAnimationBase(sf::Texture* _SpriteSheetTex)
	: mSprite(*_SpriteSheetTex)
{
}

void cAnimationBase::Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds)
{
    // Set sprite position
    mSprite.setPosition(_ObjectPosition);
    
    // Accumulate time
    mAnimationTime += _DeltaSeconds;


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
    // Set sprite position to object position
    mSprite.setPosition(_ObjectPosition);

    // Tick up animation timer
    mAnimationTime += _DeltaSeconds;

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        // check for animation complete
        if (mCurrentFrame.x >= mTotalFrames.x)
        {
            mCurrentFrame.x = 0;
            _AnimationComplete = true;
        }
        else 
        {
            // Increment frame
            mCurrentFrame.x += 1;
        }

        // calc new sprite rectangle
        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;
        // Update sprite rectangle
        mSprite.setTextureRect(mSpriteRect);

        mAnimationTime -= mFrameDuration;  // Reset timer
        
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
