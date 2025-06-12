/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerAnimator]
Description : [This class swaps between and displays animation states for the player character]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cPlayerAnimator.h"
#include "cCharacter.h"

cPlayerAnimator::cPlayerAnimator(cCharacter* _OwnerCharacter)
    : cAnimatorBase(mUpperPistolIdle)
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
    // We need to wait for callback on fire
    else if (mCurrentAnimation == &mPlayerPunchAnimation)
    {
        mPlayerPunchAnimation.Animate(PlayerPosition, DeltaSeconds, mAnimationComplete);
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

void cPlayerAnimator::SetRotation(sf::Angle _AngleToRotate)
{
    mPlayerDeathAnimation.RotateAnimation(_AngleToRotate);
    cAnimatorBase::SetRotation(_AngleToRotate);
}

void cPlayerAnimator::SwapToPistolFire(sf::Vector2f _PlayerPosition)
{
    if (mCurrentAnimation == &mPlayerPunchAnimation) return;
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

void cPlayerAnimator::SwapToPlayerPunch(sf::Vector2f _PlayerPosition)
{
    mCurrentAnimation = &mPlayerPunchAnimation;
    mPlayerPunchAnimation.RestartAnimation();
    mPlayerPunchAnimation.SetPosition(_PlayerPosition); // Set current position
}
