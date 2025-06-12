/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerAnimatorLegs]
Description : [This class swaps between and displays animation states for the player character's legs]
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
