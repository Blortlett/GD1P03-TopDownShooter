#pragma once
#include "cBoxCollider.h"
#include "cDebugWidget.h"

class cPlayerCharacter;

class cExitTrigger
{
private:
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;

public:
	cExitTrigger(sf::Vector2f _Position);
	~cExitTrigger() {}

	// Complete level on collision w/ player
	bool CheckCollideWithPlayer(cPlayerCharacter& character);

	void DebugDraw(sf::RenderWindow& _Window);

	// Delete function
	bool CheckCollideWithPoint(sf::Vector2f point);

	// getters
	sf::Vector2f GetPosition();
};