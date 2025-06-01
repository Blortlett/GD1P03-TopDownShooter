#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cFullWall.h"
#include "cHalfWall.h"


class cFileInterface;
class cDebugWidget;

class cBaseLevel
{
protected:
	// Background Texture
	sf::Texture mBackgroundTex;
	sf::Sprite* mBackgroundSprite;

	// Full wall Collider List - things such as walls player cannot shoot nor walk over
	std::vector<cFullWall*> mFullWallColliders;

	// Half wall Collider List - things such as chairs player can shoot over but can't walk over
	std::vector<cHalfWall*> mHalfWallColliders;

	// GameWindow Reference
	sf::RenderWindow& mRenderWindow;

public:
	cBaseLevel(sf::RenderWindow& _Window, std::string _BackgroundPNGFilepath);
	~cBaseLevel();

	// Updateables
	void Draw();
	void DebugDraw();

	// Add Walls to level structure
	void AddFullWallToList(cFullWall* _FullWall);
	void AddHalfWallToList(cHalfWall* _HalfWall);

	// Cleanup new objects
	void CleanupColliders();

	std::vector<cFullWall*>& GetFullWallColliderList();

	// Save/load functions
	void SaveLevel(cFileInterface& _FileInterface);
	void LoadLevel(cFileInterface& _FileInterface);
};