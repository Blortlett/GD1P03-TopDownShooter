#pragma once
#include <SFML/Graphics.hpp>

class cEnemySpawner
{
private:
	sf::CircleShape mSpawnerGraphic;

public:
	cEnemySpawner(sf::Vector2f _Position);
	~cEnemySpawner() {}

	void DebugDraw(sf::RenderWindow& _GameWindow);
};