#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cFullWall.h"
#include "cHalfWall.h"
#include "cExitDoor.h"


class cFileInterface;
class cDebugWidget;

class cBaseLevel
{
protected:
	// Background Texture
	sf::Texture mBackgroundTex;
	sf::Sprite* mBackgroundSprite;

	// -= Level Objects =-
	// Full wall Collider List - things such as walls player cannot shoot nor walk over
	std::vector<cFullWall*> mFullWallColliders;
	// Half wall Collider List - things such as chairs player can shoot over but can't walk over
	std::vector<cHalfWall*> mHalfWallColliders;
	// Exit Blocking Door
	cExitDoor* mExitDoor;

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
	// Exit door
	void AddExitDoorToLevel(cExitDoor* _ExitDoor);

	// Cleanup new objects
	void CleanupColliders();

	// Get level objects
	std::vector<cFullWall*>& GetFullWallColliderList();
	std::vector<cHalfWall*>& GetHalfWallColliderList();
	cExitDoor* GetExitDoor();

	// Save/load functions
	void SaveLevel(cFileInterface& _FileInterface);
	void LoadLevel(cFileInterface& _FileInterface);
};