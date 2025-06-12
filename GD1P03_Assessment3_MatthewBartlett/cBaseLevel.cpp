/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBaseLevel]
Description : [This base class can be extended to create new levels]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cBaseLevel.h"
#include "cDebugWidget.h"
#include "cFileInterface.h"
#include "cPlayerSpawner.h"
#include "cEnemySpawner.h"

cBaseLevel::cBaseLevel(sf::RenderWindow& _Window, std::string _BackgroundPNGFilepath)
	: mRenderWindow(_Window)
{
    if (!mBackgroundTex.loadFromFile(_BackgroundPNGFilepath))
    {
        std::cout << "Failed to load background @ " << _BackgroundPNGFilepath << std::endl; 
    }

    mBackgroundSprite = new sf::Sprite(mBackgroundTex); /// !!!!
    mBackgroundSprite->setOrigin(mBackgroundSprite->getLocalBounds().size / 2.f);
}

cBaseLevel::~cBaseLevel()
{
    if (!mLevelLoaded)
        UnloadCurrentLevel();
}

void cBaseLevel::Update(float _DeltaTime)
{
    if (mExitDoor)
    {
        mExitDoor->Update(_DeltaTime);
    }
}

void cBaseLevel::Draw()
{
    // Draw background sprite if it exists... otherwise exit this function entirely because having no background is messed up
    if (!mBackgroundSprite) return;
    mRenderWindow.draw(*mBackgroundSprite);

    // Only draw door if it exists
    if (mExitDoor)
    {
        mExitDoor->Draw(mRenderWindow);
    }
}

void cBaseLevel::DebugDraw()
{
    // Draw all widgets for full wall colliders
    for (cFullWall* fullWall : mFullWallColliders)
    {
        fullWall->DebugDraw(mRenderWindow);
    }
    // Draw all widgets for half wall colliders
    for (cHalfWall* halfWall : mHalfWallColliders)
    {
        halfWall->DebugDraw(mRenderWindow);
    }
    // Draw all enemy spawners
    for (cEnemySpawner* enemySpawner : mEnemySpawnerList)
    {
        enemySpawner->DebugDraw(mRenderWindow);
    }

    // Only draw single object if it exists
    if (mExitDoor != nullptr)
    {
        mExitDoor->DebugDraw(mRenderWindow);
    }
    if (mExitZone != nullptr)
    {
        mExitZone->DebugDraw(mRenderWindow);
    }
    if (mPlayerSpawner != nullptr)
    {
        mPlayerSpawner->DebugDraw(mRenderWindow);
    }
}

void cBaseLevel::AddFullWallToList(cFullWall* _FullWall)
{
    // Add colider to vector list
	mFullWallColliders.push_back(_FullWall);
}

void cBaseLevel::AddHalfWallToList(cHalfWall* _HalfWall)
{
    // Add colider to vector list
	mHalfWallColliders.push_back(_HalfWall);
}

void cBaseLevel::AddEnemySpawnerToList(cEnemySpawner* _EnemySpawner)
{
    mEnemySpawnerList.push_back(_EnemySpawner);
}

void cBaseLevel::AddPlayerSpawnerToLevel(cPlayerSpawner* _PlayerSpawner)
{
    delete mPlayerSpawner;
    mPlayerSpawner = _PlayerSpawner;
}

void cBaseLevel::AddExitDoorToLevel(cExitDoor* _ExitDoor)
{
    delete mExitDoor;
    mExitDoor = _ExitDoor;
    mExitDoorPosition = mExitDoor->GetPosition();
}

void cBaseLevel::AddExitZoneToLevel(cExitTrigger* _ExitZone)
{
    delete mExitZone;
    mExitZone = _ExitZone;
}

void cBaseLevel::CleanupColliders()
{
    
}

void cBaseLevel::ResetExitDoor()
{
    mExitDoor->GetCollider().MoveColliderPosition(mExitDoorPosition);
    mExitDoor->mIsDoorOpenFull = false;
    mExitDoor->mDoorOpenAmount = 84.f;
}

std::vector<cFullWall*>& cBaseLevel::GetFullWallColliderList()
{
    return mFullWallColliders;
}

std::vector<cHalfWall*>& cBaseLevel::GetHalfWallColliderList()
{
    return mHalfWallColliders;
}

std::vector<cEnemySpawner*>& cBaseLevel::GetEnemySpawnerList()
{
    return mEnemySpawnerList;
}

cPlayerSpawner* cBaseLevel::GetPlayerSpawner()
{
    return mPlayerSpawner;
}

cExitDoor* cBaseLevel::GetExitDoor()
{
    return mExitDoor;
}

cExitTrigger* cBaseLevel::GetExitTrigger()
{
    return mExitZone;
}

void cBaseLevel::SaveLevel(cFileInterface& _FileInterface)
{
    // Get file interface to save level here
    _FileInterface.SaveLevelDialog(this);
}

void cBaseLevel::LoadLevel(cFileInterface& _FileInterface)
{
    // Get file interface to load level here
    _FileInterface.LoadLevelDialog(this);
}

void cBaseLevel::UnloadCurrentLevel()
{
    // Cleanup all loaded object types
    // Delete all full wall colliders
    for (cFullWall* collider : mFullWallColliders)
    {
        delete collider;
    }
    mFullWallColliders.clear();
    // Delete all half wall colliders
    for (cHalfWall* collider : mHalfWallColliders)
    {
        delete collider;
    }
    mHalfWallColliders.clear();
    //Delete all Enemy Spawners
    for (cEnemySpawner* collider : mEnemySpawnerList)
    {
        delete collider;
    }
    mEnemySpawnerList.clear();

    //Delete player spawner
    if (mPlayerSpawner)
        delete mPlayerSpawner;
    if (mPlayerSpawner)
        delete mExitDoor;
    if (mPlayerSpawner)
        delete mExitZone;

    mLevelLoaded = false;
}
