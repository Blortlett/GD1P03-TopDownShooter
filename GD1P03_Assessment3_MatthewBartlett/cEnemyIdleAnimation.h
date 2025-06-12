/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerAnimationBase]
Description : [This class is a base class for all player animations]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cPlayerAnimationBase.h"

class cEnemyIdleAnimation : public cPlayerAnimationBase
{
private:

public:
	cEnemyIdleAnimation();
	~cEnemyIdleAnimation() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};