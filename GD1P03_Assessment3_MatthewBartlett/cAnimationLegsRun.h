/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationLegsRun]
Description : [This class holds data/functions for playing running legs animation for player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerAnimationBase.h"

class cAnimationLegsRun : public cPlayerAnimationBase
{
public:
	cAnimationLegsRun();
	~cAnimationLegsRun() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};