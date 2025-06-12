/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelManager]
Description : [This class holds a a level state machine, allowing ease of drawing one level at a time and swapping them out on load]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cLevel1.h"
#include "cLevel2.h"
#include "cLevel3.h"
#include "cFileInterface.h"
#include "cFullWall.h"
#include "cHalfWall.h"
#include "cLevelProgressTracker.h"
#include <string>

// forward declarations of level objects
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

	// Level index
	int mCurrentLevelIndex = -1;
	// Level names
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
	bool CheckLevelExit(cPlayerCharacter& _Player);

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
	
	// Unload level when exiting
	void UnloadLevel();
	void UnloadAllLevels();

	// Save / Load Dialog (more for setting up levels)
	void SaveLevel();
	void LoadLevel();

	// In game level progression
	void BeginGame();
	void AdvanceToNextLevel();

	// Reset Exit Door on reload level
	void ResetExitDoor();

	// Getters
	std::vector<cEnemySpawner*>& GetEnemySpawnerList();
	std::vector<cFullWall*>& GetFullWallList() { return mCurrentLevel->GetFullWallColliderList(); }
	std::vector<cHalfWall*>& GetHalfWallList() { return mCurrentLevel->GetHalfWallColliderList(); }
	cBaseLevel* GetCurrentLevel() { return mCurrentLevel; }
	sf::Vector2f GetLevelExitPosition() { return mCurrentLevel->GetExitTrigger()->GetPosition(); }
};