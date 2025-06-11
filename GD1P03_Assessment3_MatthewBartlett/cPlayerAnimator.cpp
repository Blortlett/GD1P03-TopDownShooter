/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimator]
Description : [Any object that would like to have animations should have a cAnimator member object attatched to it. This class can switch, animate and display animations]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cPlayerAnimator.h"
#include "cCharacter.h"

cPlayerAnimator::cPlayerAnimator(cCharacter* _OwnerCharacter)
    : cAnimatorBase(mUpperPistolIdle)
    , mUpperPistolFire(*_OwnerCharacter)
{
}

cPlayerAnimator::~cPlayerAnimator()
{
}

void cPlayerAnimator::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // We need to wait for callback on fire
    if (mCurrentAnimation == &mUpperPistolFire)
    {
        mUpperPistolFire.Animate(PlayerPosition, DeltaSeconds, mAnimationComplete);
        if (mAnimationComplete)
        {
            mAnimationComplete = false;
            SwapToPistolIdle(PlayerPosition);
        }
    }
    else
    {
        cAnimatorBase::Animate(PlayerPosition, DeltaSeconds);
    }
}

void cPlayerAnimator::SwapToPistolFire(sf::Vector2f _PlayerPosition)
{
    mCurrentAnimation = &mUpperPistolFire;
    mUpperPistolFire.RestartAnimation(); // Reset to first frame
    mAnimationComplete = false;
    mUpperPistolFire.SetPosition(_PlayerPosition); // Set current position
}

void cPlayerAnimator::SwapToPistolIdle(sf::Vector2f _PlayerPosition)
{
    mCurrentAnimation = &mUpperPistolIdle;
    mUpperPistolIdle.RestartAnimation(); // Reset to first frame
    mUpperPistolIdle.SetPosition(_PlayerPosition); // Set current position
}

void cPlayerAnimator::SwapToPlayerDeath(sf::Vector2f _PlayerPosition)
{
    mCurrentAnimation = &mPlayerDeathAnimation;
    mPlayerDeathAnimation.RestartAnimation();
    mPlayerDeathAnimation.SetPosition(_PlayerPosition); // Set current position
}
