/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationIdle]
Description : [The cAnimationIdle class contains the data and functions necessary to and dispaly the player idle-state graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerAnimationBase.h"

class cAnimationPistolIdle : public cPlayerAnimationBase
{
public:
	cAnimationPistolIdle();
	~cAnimationPistolIdle() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};