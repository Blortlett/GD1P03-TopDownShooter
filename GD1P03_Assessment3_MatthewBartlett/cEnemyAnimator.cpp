#include "cEnemyAnimator.h"

cEnemyAnimator::cEnemyAnimator()
    : cAnimatorBase(mEnemyPistolIdle)
{

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
