#include "cEnemyAnimator.h"

cEnemyAnimator::cEnemyAnimator()
    : cAnimatorBase(mEnemyPistolIdle)
{

}

void cEnemyAnimator::SwapToEnemyIdle()
{
    mCurrentAnimation = &mEnemyPistolIdle;
}

void cEnemyAnimator::SwapToEnemyDeath()
{
    mCurrentAnimation = &mEnemyDeath;
}
