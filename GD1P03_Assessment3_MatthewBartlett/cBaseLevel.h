#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cFullWall.h"
#include "cHalfWall.h"
#include "cExitDoor.h"
#include "cExitTrigger.h"


class cFileInterface;
class cDebugWidget;
class cPlayerSpawner;
class cEnemySpawner;

class cBaseLevel
{
protected:
	std::string LevelName;

	// Background Texture
	sf::Texture mBackgroundTex;
	sf::Sprite* mBackgroundSprite;

	// -= Level Objects =-
	// Full wall Collider List - things such as walls player cannot shoot nor walk over
	std::vector<cFullWall*> mFullWallColliders;
	// Half wall Collider List - things such as chairs player can shoot over but can't walk over
	std::vector<cHalfWall*> mHalfWallColliders;
	// Enemy Spawner List
	std::vector<cEnemySpawner*> mEnemySpawnerList;
	// Player Spawner
	cPlayerSpawner* mPlayerSpawner;

	// Exit Blocking Door
	cExitDoor* mExitDoor;
	// Exit Zone behind ExitDoor
	cExitTrigger* mExitZone;

	// GameWindow Reference
	sf::RenderWindow& mRenderWindow;

public:
	cBaseLevel(sf::RenderWindow& _Window, std::string _BackgroundPNGFilepath);
	~cBaseLevel();

	// Updateables
	void Update(float _DeltaTime);
	void Draw();
	void DebugDraw();

	// -= Add Objects to level structure =-
	// Walls
	void AddFullWallToList(cFullWall* _FullWall);
	void AddHalfWallToList(cHalfWall* _HalfWall);
	// Enemy Spawner
	void AddEnemySpawnerToList(cEnemySpawner* _EnemySpawner);
	// PlayerSpawner
	void AddPlayerSpawnerToLevel(cPlayerSpawner* _PlayerSpawner);
	// Exit door // Blocks access to exit zone
	void AddExitDoorToLevel(cExitDoor* _ExitDoor);
	// Exit zone collider
	void AddExitZoneToLevel(cExitTrigger* _ExitZone);

	// Cleanup new objects
	void CleanupColliders();

	// Get level objects
	std::vector<cFullWall*>& GetFullWallColliderList();
	std::vector<cHalfWall*>& GetHalfWallColliderList();
	std::vector<cEnemySpawner*>& GetEnemySpawnerList();
	cPlayerSpawner* GetPlayerSpawner();
	cExitDoor* GetExitDoor();
	cExitTrigger* GetExitTrigger();

	// Save/load functions
	void SaveLevel(cFileInterface& _FileInterface);
	void LoadLevel(cFileInterface& _FileInterface);
	virtual void LoadLevelByName(cFileInterface& _FileInterface) = 0;
};