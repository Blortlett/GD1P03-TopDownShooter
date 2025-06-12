/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemyPistolFire]
Description : [This class stores data/functionality to animate enemy pistol fire]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerAnimationBase.h"

class cEnemyPistolFireAnimation : public cPlayerAnimationBase
{
private:
	bool mAnimationComplete;

public:
	cEnemyPistolFireAnimation();
	~cEnemyPistolFireAnimation() {}

};