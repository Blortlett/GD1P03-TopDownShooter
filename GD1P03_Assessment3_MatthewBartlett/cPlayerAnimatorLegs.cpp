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
#include "cPlayerAnimatorLegs.h"

cPlayerAnimatorLegs::cPlayerAnimatorLegs()
    : cAnimatorBase(mLowerLegsIdle)
{
}

cPlayerAnimatorLegs::~cPlayerAnimatorLegs()
{
}

void cPlayerAnimatorLegs::SwapToIdle()
{
    mCurrentAnimation = &mLowerLegsIdle;
}

void cPlayerAnimatorLegs::SwapToRun()
{
    mCurrentAnimation = &mLowerLegsRun;
}
