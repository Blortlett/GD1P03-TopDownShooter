/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimatorBase]
Description : [This base class can be extended by animator classes to swap between and display animation states on an object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "cAnimationBase.h"

class cAnimatorBase
{
protected:
	cAnimationBase* mCurrentAnimation;
public:
	cAnimatorBase(cAnimationBase& _StartAnimation);
	~cAnimatorBase() {}

	// Animate and Draw
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow);
	//Rotate Animation
	void SetRotation(sf::Angle _AngleToRotate);
	// Swap animation
	void SwapAnimation(cAnimationBase* _Animation);

	// Getters
	sf::Angle GetRotation();
};