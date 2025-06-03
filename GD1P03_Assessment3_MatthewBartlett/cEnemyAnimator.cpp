#include "cEnemyAnimator.h"

cEnemyAnimator::cEnemyAnimator()
    : cAnimatorBase(mEnemyPistolIdle)
{

}

void cEnemyAnimator::SwapToEnemyDeath()
{
    mCurrentAnimation = &mEnemyDeath;
}
