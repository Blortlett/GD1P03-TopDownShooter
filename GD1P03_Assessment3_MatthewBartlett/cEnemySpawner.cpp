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

void cEnemySpawner::SpawnEnemy()
{

}

void cEnemySpawner::DebugDraw(sf::RenderWindow& _GameWindow)
{
	_GameWindow.draw(mSpawnerGraphic);
}

sf::Vector2f cEnemySpawner::GetPosition()
{
	return mSpawnerGraphic.getPosition();
}
