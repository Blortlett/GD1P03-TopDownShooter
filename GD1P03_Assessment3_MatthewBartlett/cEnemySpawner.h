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

#pragma once
#include <SFML/Graphics.hpp>
#include "cEnemyCharacter.h"

class cEnemySpawner
{
private:
	sf::CircleShape mSpawnerGraphic;

public:
	cEnemySpawner(sf::Vector2f _Position);
	~cEnemySpawner() {}

	//Debug
	void DebugDraw(sf::RenderWindow& _GameWindow);

	// Getters
	sf::Vector2f GetPosition();
};