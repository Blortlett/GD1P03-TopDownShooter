#pragma once
#include "cLevel1.h"

class cLevelManager
{
private:
	//Current Level
	cBaseLevel* mCurrentLevel;
	// Level List
	cLevel1 mLevel;

	// Game window reference
	sf::RenderWindow& mGameWindow;  // Not sure we will need to save this

public:
	// 'Structaz
	cLevelManager(sf::RenderWindow& _Window);
	~cLevelManager() {}

	// Updateables
	void Update();
	void Draw();


	// Level building functions // player probably won't know about these
	void AddFullWall(cBoxCollider* _FullWallCollider);
	void AddHalfWall(cBoxCollider* _HalfWallCollider);
};