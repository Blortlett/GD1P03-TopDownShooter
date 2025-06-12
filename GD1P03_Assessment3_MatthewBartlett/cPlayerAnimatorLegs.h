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
#pragma once
#include "cAnimatorBase.h"
#include "cAnimationLegsIdle.h"
#include "cAnimationLegsRun.h"


class cPlayerAnimatorLegs : public cAnimatorBase
{
private:
	// Animations
	cAnimationLegsIdle mLowerLegsIdle;
	cAnimationLegsRun mLowerLegsRun;

public:
	// Constructors
	cPlayerAnimatorLegs();
	~cPlayerAnimatorLegs();

	// Swap Animations
	void SwapToIdle();
	void SwapToRun();
};