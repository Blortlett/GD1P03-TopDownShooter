#include "cLevelManager.h"

cLevelManager::cLevelManager(sf::RenderWindow& _Window)
	: mGameWindow(_Window)
	, mLevel(_Window)
{
	// Set Current level as Level1
	mCurrentLevel = &mLevel;
}

void cLevelManager::Update()
{
}

void cLevelManager::Draw()
{
	mCurrentLevel->Draw();
}

void cLevelManager::AddFullWall(cBoxCollider* _FullWallCollider)
{
	mCurrentLevel->AddFullWallToList(_FullWallCollider);
}

void cLevelManager::AddHalfWall(cBoxCollider* _HalfWallCollider)
{

}

