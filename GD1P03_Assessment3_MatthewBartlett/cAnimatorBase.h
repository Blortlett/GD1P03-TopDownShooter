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
};