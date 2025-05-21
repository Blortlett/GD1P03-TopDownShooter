#pragma once
#include "cBullet.h"

class cProjectileManager
{
private:
	// Player Bullets
	std::array<cBullet, 15> mPlayerBulletList;
	int mPlayerMaxBulletIndex = 14;
	int mPlayerCurrentBulletIndex = mPlayerMaxBulletIndex;

	// Game Window
	sf::RenderWindow& mGameWindow;
public:
	// Constructor n dat
	cProjectileManager(sf::RenderWindow& _Window);
	~cProjectileManager() {}

	void FirePlayerBullet(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory);

	// Updater
	void Update(float _DeltaTime);
};