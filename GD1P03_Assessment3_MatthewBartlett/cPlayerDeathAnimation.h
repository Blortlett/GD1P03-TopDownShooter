/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerDeathAnimation]
Description : [this class stores functions/data for animating player death animation]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cPlayerAnimationBase.h"

class cPlayerDeathAnimation : public cPlayerAnimationBase
{
private:

public:
	cPlayerDeathAnimation();
	~cPlayerDeathAnimation() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};