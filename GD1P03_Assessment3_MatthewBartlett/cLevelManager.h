#pragma once
#include "cLevel1.h"
#include "cLevel2.h"
#include "cLevel3.h"
#include "cFileInterface.h"
#include "cFullWall.h"
#include "cHalfWall.h"
#include "cLevelProgressTracker.h"
#include <string>

// forward declarations
class cPlayerCharacter;
class cExitTrigger;
class cPlayerSpawner;
class cEnemySpawner;


class cLevelManager
{
private:

	// Level objects
	cLevel1 mLevel1;
	cLevel2 mLevel2;
	cLevel3 mLevel3;

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
	void Update(float _DeltaTime);
	void Draw();
	void DebugDraw();

	// -= Collisions =-
	void CheckPlayerWallCollisions(cPlayerCharacter& _Player);

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

	void LoadLevelByObject();

	// Getters
	std::vector<cEnemySpawner*>& GetEnemySpawnerList();
	std::vector<cFullWall*>& GetFullWallList() { return mCurrentLevel->GetFullWallColliderList(); }
};