#include "cLevelManager.h"
#include "cPlayerCharacter.h"

cLevelManager::cLevelManager(sf::RenderWindow& _Window)
	: mLevel1(_Window)
	, mCurrentLevel(&mLevel1)
	, mFileInterface(mCurrentLevel)
{
}

void cLevelManager::Update()
{
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
	sf::Vector2f CollisionDirection;
	// Get all fullwalls in level
	std::vector<cFullWall*>& FullWallColliderList = mCurrentLevel->GetFullWallColliderList();

	// Check collisions
	for (size_t i = 0; i < FullWallColliderList.size(); ++i) {
		FullWallColliderList[i]->CheckCollideWithPlayer(_Player, CollisionDirection);
	}
}

void cLevelManager::AddFullWall(cFullWall* _FullWallCollider)
{
	mCurrentLevel->AddFullWallToList(_FullWallCollider);
}

void cLevelManager::AddHalfWall(cHalfWall* _HalfWallCollider)
{

}

void cLevelManager::SaveLevel()
{
	mCurrentLevel->SaveLevel(mFileInterface);
}

void cLevelManager::LoadLevel()
{
	mCurrentLevel->LoadLevel(mFileInterface);
}

