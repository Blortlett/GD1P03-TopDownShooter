#pragma once
#include "cLevel1.h"
#include "cFileInterface.h"
#include "cFullWall.h"
#include "cHalfWall.h"

// forward declarations
class cEnemyManager;
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

public:
	// 'Structaz
	cLevelManager(sf::RenderWindow& _Window);
	~cLevelManager() {}

	// Updateables
	void Update();
	void Draw();
	void DebugDraw();

	// -= Collisions =-
	void CheckPlayerWallCollisions(cPlayerCharacter& _Player);
	// Bullet to enemy collision
	void CheckBulletToEnemyCollision(cProjectileManager& _ProjectileManager, cEnemyManager& _EnemyManager);

	// -= Level Editing =-
	// Add wall
	void AddFullWall(cFullWall* _FullWallCollider);
	void AddHalfWall(cHalfWall* _HalfWallCollider);
	// Delete wall
	void TryDeleteWall(sf::Vector2f pointCollision);

	// Save / Load level data
	void SaveLevel();
	void LoadLevel();
};