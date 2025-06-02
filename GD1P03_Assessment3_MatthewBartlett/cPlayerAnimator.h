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
#pragma once
#include "cAnimatorBase.h"
#include "cAnimationPistolIdle.h"


class cPlayerAnimator : public cAnimatorBase
{
public:
	 // Constructors
	cPlayerAnimator();
	~cPlayerAnimator();

private:
	// Animations
	cAnimationPistolIdle mUpperPistolIdle;
};