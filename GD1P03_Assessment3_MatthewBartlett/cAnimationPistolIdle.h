/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationPistolIdle]
Description : [This class holds data/functions for playing pistol idle animation for player chatacter]
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