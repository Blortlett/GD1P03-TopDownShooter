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