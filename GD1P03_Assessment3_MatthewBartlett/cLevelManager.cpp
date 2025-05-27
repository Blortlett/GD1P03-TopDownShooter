#include "cLevelManager.h"
#include "cPlayerCharacter.h"

cLevelManager::cLevelManager(sf::RenderWindow& _Window)
	: mGameWindow(_Window)
	, mLevel1(_Window)
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

void cLevelManager::CheckPlayerWallCollisions(cPlayerCharacter& _Player)
{
	// Check player collision with all FullWalls
	sf::Vector2f collisionDirection;
	std::vector<cBoxCollider*>& FullWallColliderList = mCurrentLevel->GetFullWallColliderList();
	bool isColliding = false;
	// Check collisions
	for (size_t i = 0; i < FullWallColliderList.size(); ++i) {
		if (FullWallColliderList[i]->CheckCollision(_Player.GetCollider(), collisionDirection, 1.0f))
			isColliding = true;
	}
}

void cLevelManager::AddFullWall(cBoxCollider* _FullWallCollider)
{
	mCurrentLevel->AddFullWallToList(_FullWallCollider);
}

void cLevelManager::AddHalfWall(cBoxCollider* _HalfWallCollider)
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

