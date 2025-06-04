#pragma once
#include "cLevel1.h"
#include "cFileInterface.h"
#include "cFullWall.h"
#include "cHalfWall.h"
#include <string>

// forward declarations
class cEnemyManager;
class cPlayerCharacter;
class cExitTrigger;
class cPlayerSpawner;
class cEnemySpawner;


class cLevelManager
{
private:
	bool mLevelComplete = false;

	// Level List
	cLevel1 mLevel1;

	//Current Level
	cBaseLevel* mCurrentLevel;

	// Loading/Saving object
	cFileInterface mFileInterface;

	std::string LevelNames[3] = { "Level1", "Level2", "Level3" };

public:
	// 'Structaz
	cLevelManager(sf::RenderWindow& _Window);
	~cLevelManager() {}

	// Updateables
	void TrackLevelComplete(cEnemyManager& _EnemyManager);
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
	void AddExitDoor(cExitDoor* _ExitDoorObject); // Exit blocker
	// Spawners
	void AddPlayerSpawner(cPlayerSpawner* _PlayerSpawner);
	void AddEnemySpawner(cEnemySpawner* _EnemySpawner);
	// Player exit
	void AddExitZone(cExitTrigger* _ExitZoneObject);
	// Delete wall
	void TryDeleteWall(sf::Vector2f pointCollision);

	// Save / Load level data
	void SaveLevel();
	void LoadLevel();
};