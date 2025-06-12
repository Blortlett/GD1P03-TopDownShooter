/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cExitTrigger]
Description : [This class can be placed in a level to give player somewhere to spawn/respawn]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cPlayerSpawner.h"

cPlayerSpawner::cPlayerSpawner(sf::Vector2f _Position)
{
	mSpawnerGraphic.setPosition(_Position);
	mSpawnerGraphic.setRadius(5.f);
	mSpawnerGraphic.setFillColor(sf::Color::Transparent);
	mSpawnerGraphic.setOutlineColor(sf::Color::Green);
	mSpawnerGraphic.setOutlineThickness(.5f);
	mSpawnerGraphic.setOrigin(sf::Vector2f(5.f, 5.f));
}

void cPlayerSpawner::DebugDraw(sf::RenderWindow& _GameWindow)
{
	_GameWindow.draw(mSpawnerGraphic);
}

sf::Vector2f cPlayerSpawner::GetPosition()
{
	return mSpawnerGraphic.getPosition();
}
