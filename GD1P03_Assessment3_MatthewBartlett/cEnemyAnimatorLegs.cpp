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
#include "cEnemyAnimatorLegs.h"

cEnemyAnimatorLegs::cEnemyAnimatorLegs()
    : cAnimatorBase(mLowerLegsIdle)
{
}

cEnemyAnimatorLegs::~cEnemyAnimatorLegs()
{
}

void cEnemyAnimatorLegs::SwapToIdle()
{
    mCurrentAnimation = &mLowerLegsIdle;
}

void cEnemyAnimatorLegs::SwapToRun()
{
    mCurrentAnimation = &mLowerLegsRun;
}

void cEnemyAnimatorLegs::ClearAnimation()
{
    mCurrentAnimation = nullptr;
}
