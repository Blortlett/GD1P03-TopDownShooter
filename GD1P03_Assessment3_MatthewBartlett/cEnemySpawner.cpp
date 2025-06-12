/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemySpawner]
Description : [This class can can be placed in a level to instruct enemies where to spawn]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cEnemySpawner.h"

cEnemySpawner::cEnemySpawner(sf::Vector2f _Position)
{
	mSpawnerGraphic.setPosition(_Position);
	mSpawnerGraphic.setRadius(5.f);
	mSpawnerGraphic.setFillColor(sf::Color::Transparent);
	mSpawnerGraphic.setOutlineColor(sf::Color::Magenta);
	mSpawnerGraphic.setOutlineThickness(.5f);
	mSpawnerGraphic.setOrigin(sf::Vector2f(5.f, 5.f));
}

void cEnemySpawner::DebugDraw(sf::RenderWindow& _GameWindow)
{
	_GameWindow.draw(mSpawnerGraphic);
}

sf::Vector2f cEnemySpawner::GetPosition()
{
	return mSpawnerGraphic.getPosition();
}
