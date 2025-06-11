#include "cEnemyAnimator.h"

cEnemyAnimator::cEnemyAnimator()
    : cAnimatorBase(mEnemyPistolIdle)
{

}

void cEnemyAnimator::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // We need to wait for callback on fire
    if (mCurrentAnimation == &mEnemyPistolFire)
    {
        std::cout << "Pistol fire frame" << std::endl;
        mEnemyPistolFire.Animate(PlayerPosition, DeltaSeconds, mAnimationComplete);
        if (mAnimationComplete)
        {
            std::cout << "Pistol Fire Animation Completed" << std::endl;
            mAnimationComplete = false;
            SwapToEnemyIdle(PlayerPosition);
        }
    }
    else
    {
        cAnimatorBase::Animate(PlayerPosition, DeltaSeconds);
    }
}

void cEnemyAnimator::SetRotation(sf::Angle _AngleToRotate)
{
    mEnemyDeath.RotateAnimation(_AngleToRotate);
    cAnimatorBase::SetRotation(_AngleToRotate);
}

void cEnemyAnimator::SwapToEnemyIdle(sf::Vector2f _CharacterPosition)
{
    mCurrentAnimation = &mEnemyPistolIdle;
    mEnemyPistolIdle.RestartAnimation(); // Reset to first frame
    mEnemyPistolIdle.SetPosition(_CharacterPosition); // Set current position
}

void cEnemyAnimator::SwapToEnemyDeath(sf::Vector2f _CharacterPosition)
{
    mCurrentAnimation = &mEnemyDeath;
    mEnemyDeath.RestartAnimation(); // Reset to first frame
    mEnemyDeath.SetPosition(_CharacterPosition); // Set current position
}

void cEnemyAnimator::SwapToEnemyFire(sf::Vector2f _CharacterPosition)
{
    mCurrentAnimation = &mEnemyPistolFire;
    mEnemyPistolFire.RestartAnimation(); // Reset to first frame
    mAnimationComplete = false;
    mEnemyPistolFire.SetPosition(_CharacterPosition); // Set current position
}
