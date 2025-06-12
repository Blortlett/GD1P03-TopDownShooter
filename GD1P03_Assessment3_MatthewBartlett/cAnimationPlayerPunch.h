/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationPlayerPunch]
Description : [This class holds data/functions for playing player punch animation for player chatacter]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerAnimationBase.h"

class cAnimationPlayerPunch : public cPlayerAnimationBase
{
private:
	bool mAnimationComplete;

public:
	cAnimationPlayerPunch();
	~cAnimationPlayerPunch() {}

};