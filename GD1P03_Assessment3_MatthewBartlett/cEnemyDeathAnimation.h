/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemyDeathAnimation]
Description : [This class holds enemy death animation data/functions]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cPlayerAnimationBase.h"

class cEnemyDeathAnimation : public cPlayerAnimationBase
{
private:

public:
	cEnemyDeathAnimation();
	~cEnemyDeathAnimation() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};