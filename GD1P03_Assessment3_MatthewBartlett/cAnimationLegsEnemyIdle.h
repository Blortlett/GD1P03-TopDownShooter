/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationLegsEnemyIdle]
Description : [This class holds enemy legs idle animation data/functions]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerAnimationBase.h"

class cAnimationLegsEnemyIdle: public cPlayerAnimationBase
{
public:
	cAnimationLegsEnemyIdle();
	~cAnimationLegsEnemyIdle() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};