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

cPlayerAnimator::cPlayerAnimator()
    : cAnimatorBase(mUpperPistolIdle)
{
}

cPlayerAnimator::~cPlayerAnimator()
{
}

void cPlayerAnimator::SwapToPistolFire()
{
    mCurrentAnimation = &mUpperPistolFire;
}

void cPlayerAnimator::SwapToPistolIdle()
{
    mCurrentAnimation = &mUpperPistolIdle;
}
