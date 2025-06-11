#include "cLevelProgressTracker.h"

cLevelProgressTracker::cLevelProgressTracker()
	: mLevelWalls(nullptr) // DODGY!! but just might work >:)
{
}

void cLevelProgressTracker::OnLoadSetEnemyCount(int _EnemyCount)
{
	mLevelMaxEnemies = _EnemyCount;
	mEnemyCount = mLevelMaxEnemies;
}

void cLevelProgressTracker::ReduceEnemyCount()
{
	mEnemyCount--;
}

bool cLevelProgressTracker::CheckLevelComplete()
{
	return mEnemyCount <= 0;
}

void cLevelProgressTracker::ResetEnemyCount()
{
	mEnemyCount = mLevelMaxEnemies;
}
