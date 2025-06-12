/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelManager]
Description : [This class holds a a level state machine, allowing ease of drawing one level at a time and swapping them out on load]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cLevelManager.h"
#include "cPlayerCharacter.h"
#include "cProjectileManager.h"
#include "cExitTrigger.h"
#include "cPlayerSpawner.h"
#include "cEnemySpawner.h"
#include "cLevelProgressTracker.h"



cLevelManager::cLevelManager(sf::RenderWindow& _Window)
	: mLevel1(_Window)
	, mLevel2(_Window)
	, mLevel3(_Window)
	, mCurrentLevel(&mLevel1)
	, mFileInterface(mCurrentLevel)
{
}

void cLevelManager::Update(float _DeltaTime)
{
	// Update levels exit door
	mCurrentLevel->Update(_DeltaTime);
}

void cLevelManager::Draw()
{
	mCurrentLevel->Draw();
}

void cLevelManager::DebugDraw()
{
	mCurrentLevel->DebugDraw();
}

void cLevelManager::CheckPlayerWallCollisions(cPlayerCharacter& _Player)
{
	// Collision function will modify this
	sf::Vector2f CollisionDirection;
	// Get all full walls in level
	std::vector<cFullWall*>& FullWallColliderList = mCurrentLevel->GetFullWallColliderList();
	std::vector<cHalfWall*>& HalfWallColliderList = mCurrentLevel->GetHalfWallColliderList();

	// Check full wall collisions
	for (size_t i = 0; i < FullWallColliderList.size(); ++i) {
		FullWallColliderList[i]->CheckCollideWithPlayer(_Player, CollisionDirection);
	}
	// Check half wall collisions
	for (size_t i = 0; i < HalfWallColliderList.size(); ++i) {
		HalfWallColliderList[i]->CheckCollideWithPlayer(_Player, CollisionDirection);
	}

	// Check exit door collision seperately
	cExitDoor* ExitDoor = mCurrentLevel->GetExitDoor();
	if (ExitDoor)
	{
		ExitDoor->CheckCollideWithPlayer(_Player, CollisionDirection);
	}
}

bool cLevelManager::CheckLevelExit(cPlayerCharacter& _Player)
{
	// Check player reached end of level zone / exit zone collider
	cExitTrigger* ExitZone = mCurrentLevel->GetExitTrigger();

	// If exit zone does not exist, don't worry about rest of function
	if (ExitZone && ExitZone->CheckCollideWithPlayer(_Player))
	{
		return true; // Player has reached the level exit
	}
	return false; // Player not @ exit yet
}

void cLevelManager::AddFullWall(cFullWall* _FullWallCollider)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddFullWallToList(_FullWallCollider);
}

void cLevelManager::AddHalfWall(cHalfWall* _HalfWallCollider)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddHalfWallToList(_HalfWallCollider);
}

void cLevelManager::AddExitDoor(cExitDoor* _ExitDoorObject)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddExitDoorToLevel(_ExitDoorObject);
}

void cLevelManager::AddPlayerSpawner(cPlayerSpawner* _PlayerSpawner)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddPlayerSpawnerToLevel(_PlayerSpawner);
}

void cLevelManager::AddEnemySpawner(cEnemySpawner* _EnemySpawner)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddEnemySpawnerToList(_EnemySpawner);
}

void cLevelManager::AddExitZone(cExitTrigger* _ExitZoneObject)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddExitZoneToLevel(_ExitZoneObject);
}

void cLevelManager::TryDeleteWall(sf::Vector2f pointCollision)
{
	// Get FullWall List
	std::vector<cFullWall*>& FullWallList = mCurrentLevel->GetFullWallColliderList();
	// Ruffle through it
	for (size_t i = 0; i < FullWallList.size(); ++i)
	{
		// If point collides with the wall
		if (FullWallList[i]->CheckCollideWithPoint(pointCollision))
		{
			// Delete it
			delete FullWallList[i];
			// Remove item from list
			FullWallList.erase(FullWallList.begin() + i);
		}
	}
}

void cLevelManager::UnloadLevel()
{
	mCurrentLevel->UnloadCurrentLevel();
}

void cLevelManager::UnloadAllLevels()
{
	mCurrentLevelIndex = 0;
	/*if (mLevel1.mLevelLoaded)
		mLevel1.UnloadCurrentLevel();
	if (mLevel2.mLevelLoaded)
		mLevel2.UnloadCurrentLevel();
	if (mLevel3.mLevelLoaded)
		mLevel3.UnloadCurrentLevel();*/
}


void cLevelManager::SaveLevel()
{
	mCurrentLevel->SaveLevel(mFileInterface);
}

void cLevelManager::LoadLevel()
{
	mCurrentLevel->LoadLevel(mFileInterface);
}

void cLevelManager::BeginGame()
{
	mCurrentLevel = &mLevel1;
	// Load the new level
	//mCurrentLevel->LoadLevelByName(mFileInterface);
	cLevelProgressTracker::GetInstance().SetWallVector(mCurrentLevel->GetFullWallColliderList());
}

void cLevelManager::AdvanceToNextLevel()
{
	if (mCurrentLevel == &mLevel3)
		cGameSettings::GetInstance().SetGameState(EGameState::MainMenu);

	// Increment level index and select the next level
	mCurrentLevelIndex = (mCurrentLevelIndex + 1) % 3; // Cycle through levels (0, 1, 2)
	if (mCurrentLevelIndex == 0)
		mCurrentLevel = &mLevel1;
	else if (mCurrentLevelIndex == 1)
		mCurrentLevel = &mLevel2;
	else if (mCurrentLevelIndex == 2)
		mCurrentLevel = &mLevel3;
	else
	{	// Game complete, return to main menu
		UnloadAllLevels();
		cGameSettings::GetInstance().SetGameState(EGameState::MainMenu);
	}


	// Load the new level
	if (!mCurrentLevel->mLevelLoaded)
		mCurrentLevel->LoadLevelByName(mFileInterface);
	mCurrentLevel->ResetExitDoor();
	cLevelProgressTracker::GetInstance().SetWallVector(mCurrentLevel->GetFullWallColliderList());

}

void cLevelManager::ResetExitDoor()
{
	mCurrentLevel->ResetExitDoor();
}

std::vector<cEnemySpawner*>& cLevelManager::GetEnemySpawnerList()
{
	return mCurrentLevel->GetEnemySpawnerList();
}

