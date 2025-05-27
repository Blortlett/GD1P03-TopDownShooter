#pragma once
#include "cLevel1.h"
#include "cFileInterface.h"
// forward declarations
class cPlayerCharacter;


class cLevelManager
{
private:
	// Level List
	cLevel1 mLevel1;
	
	//Current Level
	cBaseLevel* mCurrentLevel;

	// Game window reference
	sf::RenderWindow& mGameWindow;  // Not sure we will need to save this
	
	// Loading/Saving object
	cFileInterface mFileInterface;

public:
	// 'Structaz
	cLevelManager(sf::RenderWindow& _Window);
	~cLevelManager() {}

	// Updateables
	void Update();
	void Draw();

	// Collisions
	void CheckPlayerWallCollisions(cPlayerCharacter& _Player);

	// Level Editing
	void AddFullWall(cBoxCollider* _FullWallCollider);
	void AddHalfWall(cBoxCollider* _HalfWallCollider);

	// Save / Load level data
	void SaveLevel();
	void LoadLevel();
};