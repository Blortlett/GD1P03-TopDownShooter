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
