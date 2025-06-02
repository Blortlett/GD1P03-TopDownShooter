#pragma once
#include "cLevel1.h"
#include "cFileInterface.h"
#include "cFullWall.h"
#include "cHalfWall.h"
#include "cEnemyManager.h"
// forward declarations
class cPlayerCharacter;


class cLevelManager
{
private:
	// Level List
	cLevel1 mLevel1;
	
	//Current Level
	cBaseLevel* mCurrentLevel;
	
	// Loading/Saving object
	cFileInterface mFileInterface;

	// Enemy manager reference
	cEnemyManager& mEnemyManager;
	// Projectile manager reference
	cProjectileManager& mProjectileManager;

public:
	// 'Structaz
	cLevelManager(sf::RenderWindow& _Window, cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager);
	~cLevelManager() {}

	// Updateables
	void Update();
	void Draw();
	void DebugDraw();

	// -= Collisions =-
	void CheckPlayerWallCollisions(cPlayerCharacter& _Player);
	// Bullet to enemy collision
	void CheckEnemyBulletCollision();

	// Level Editing
	void AddFullWall(cFullWall* _FullWallCollider);
	void AddHalfWall(cHalfWall* _HalfWallCollider);

	// Save / Load level data
	void SaveLevel();
	void LoadLevel();
};