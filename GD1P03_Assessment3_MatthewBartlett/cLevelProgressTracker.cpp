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
