/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [iBehavior]
Description : [This interface class can be extended to easily add new enemy behaviors]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class iBehavior
{
private:

public:
	iBehavior() {}
	~iBehavior() {}

	virtual void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) = 0;
};