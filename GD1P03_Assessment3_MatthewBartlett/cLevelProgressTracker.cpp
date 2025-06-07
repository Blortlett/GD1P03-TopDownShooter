#include "cLevelProgressTracker.h"

cLevelProgressTracker::cLevelProgressTracker()
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
	std::cout << "TotalEnemies: " << mLevelMaxEnemies << "  Enemies Remaining: " << mEnemyCount << std::endl;
}

bool cLevelProgressTracker::CheckLevelComplete()
{
	return mLevelMaxEnemies <= mEnemyCount;
}
