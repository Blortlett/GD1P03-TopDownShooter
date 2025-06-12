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

#pragma once
#include <SFML/Graphics.hpp>

class cPlayerSpawner
{
private:
	sf::CircleShape mSpawnerGraphic;

public:
	cPlayerSpawner(sf::Vector2f _Position);

	void DebugDraw(sf::RenderWindow& _GameWindow);
	sf::Vector2f GetPosition();
};