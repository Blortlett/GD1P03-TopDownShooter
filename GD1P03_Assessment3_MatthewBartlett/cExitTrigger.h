/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cExitTrigger]
Description : [This class can can be placed in a level to let player collide with to leave level]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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