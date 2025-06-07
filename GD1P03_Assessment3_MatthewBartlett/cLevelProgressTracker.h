#pragma once
#include <iostream>

class cLevelProgressTracker
{
private:
	cLevelProgressTracker();
	~cLevelProgressTracker() {}


	int mLevelMaxEnemies;
	int mEnemyCount;

public:
	void OnLoadSetEnemyCount(int _EnemyCount);
	void ReduceEnemyCount();
	bool CheckLevelComplete();










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