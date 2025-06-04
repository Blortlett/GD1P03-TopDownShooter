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