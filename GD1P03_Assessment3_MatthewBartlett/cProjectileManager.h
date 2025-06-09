#pragma once
#include "cBullet.h"

class cProjectileManager
{
private:
	// Player Bullets
	std::array<cBullet, 15> mPlayerBulletList;
	std::array<cBullet, 20> mEnemyBulletList;

	int mPlayerMaxBulletIndex = 14;
	int mPlayerCurrentBulletIndex = mPlayerMaxBulletIndex;

	int mEnemyMaxBulletIndex = 19;
	int mEnemyCurrentBulletIndex = mEnemyMaxBulletIndex;

	// Game Window
	sf::RenderWindow& mGameWindow;
public:
	// Constructor n dat
	cProjectileManager(sf::RenderWindow& _Window);
	~cProjectileManager() {}

	void FirePlayerBullet(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory);
	void FireEnemyBullet(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory);

	// Updater
	void Update(float _DeltaTime);

	std::array<cBullet, 15>& GetPlayerBulletList() { return mPlayerBulletList; }
	std::array<cBullet, 20>& GetEnemyBulletList() { return mEnemyBulletList; }
};