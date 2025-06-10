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