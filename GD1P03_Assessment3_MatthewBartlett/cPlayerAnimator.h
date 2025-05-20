/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimator]
Description : [Any object that would like to have animations should have a cAnimator member object attatched to it. This class can switch, animate and display animations]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "cAnimationPistolIdle.h"


class cPlayerAnimator
{
public:
	cPlayerAnimator();
	~cPlayerAnimator();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow);
	// Animation Swap Functions

private:
	// Animation variables
	
	// Animation state holder
	cAnimationBase* mCurrentAnimation;
	// Animations
	cAnimationPistolIdle mUpperPistolIdle;
};