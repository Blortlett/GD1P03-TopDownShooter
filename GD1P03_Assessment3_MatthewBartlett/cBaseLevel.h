#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cBoxCollider.h"
#include "cDebugWidget.h"

class cBaseLevel
{
protected:
	// Background Texture
	sf::Texture mBackgroundTex;
	sf::Sprite* mBackgroundSprite;

	// Full wall Collider List - things such as walls player cannot shoot nor walk over
	std::vector<cBoxCollider*> mFullWallColliders;
	std::vector<cDebugWidget*> mDebugGFXFullWall;

	// Half wall Collider List - things such as chairs player can shoot over but can't walk over
	std::vector<cBoxCollider*> mHalfWallColliders;
	std::vector<cDebugWidget*> mDebugGFXHalfWall;

	// GameWindow Reference
	sf::RenderWindow& mRenderWindow;

public:
	cBaseLevel(sf::RenderWindow& _Window);
	~cBaseLevel();

	// Updateables
	virtual void Draw() = 0;
	void DebugDraw();

	// Add Walls to level structure
	void AddFullWallToList(cBoxCollider* _FullWall);
	void AddHalfWallToList(cBoxCollider* _HalfWall);

	// Cleanup new objects
	void CleanupColliders();
	void CleanupDebugWidgets();
};