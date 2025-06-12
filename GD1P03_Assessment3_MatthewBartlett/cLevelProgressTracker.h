/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelProgressTracker]
Description : [This class deals with tracking if the level is complete yet]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <iostream>
#include <vector>

class cFullWall;

class cLevelProgressTracker
{
private:
	cLevelProgressTracker();
	~cLevelProgressTracker() {}
	// Enemy count
	int mLevelMaxEnemies;
	int mEnemyCount;

	// Wall vector reference:
	std::vector<cFullWall*>* mLevelWalls;

public:
	void OnLoadSetEnemyCount(int _EnemyCount);
	void ReduceEnemyCount();
	bool CheckLevelComplete();

	// Reset enemy count on player death
	void ResetEnemyCount();


	// Setters
	void SetWallVector(std::vector<cFullWall*>& _LevelWalls) { mLevelWalls = &_LevelWalls; }

	// Getters
	std::vector<cFullWall*>* GetWallVector() { return mLevelWalls; }






	// Singleton crap....
	// Get the single instance of the class
	static cLevelProgressTracker& GetInstance()
	{
		static cLevelProgressTracker instance; // Static instance created on first call
		return instance;
	}
	// Delete copy constructor and assignment operator to prevent copying
	cLevelProgressTracker(const cLevelProgressTracker&) = delete;
	cLevelProgressTracker& operator=(const cLevelProgressTracker&) = delete;
};