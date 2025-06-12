/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationPistolFire]
Description : [This class holds data/functions for playing pistol fire animation for player chatacter]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerAnimationBase.h"

class cAnimationPistolFire: public cPlayerAnimationBase
{
private:
	bool mAnimationComplete;

public:
	cAnimationPistolFire();
	~cAnimationPistolFire() {}
	
};