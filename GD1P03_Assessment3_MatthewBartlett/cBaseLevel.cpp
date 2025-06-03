#include "cBaseLevel.h"
#include "cDebugWidget.h"
#include "cFileInterface.h"

cBaseLevel::cBaseLevel(sf::RenderWindow& _Window, std::string _BackgroundPNGFilepath)
	: mRenderWindow(_Window)
{
    if (!mBackgroundTex.loadFromFile(_BackgroundPNGFilepath))
    {
        std::cout << "Failed to load background @ " << _BackgroundPNGFilepath << std::endl;
    }

    mBackgroundSprite = new sf::Sprite(mBackgroundTex);
    mBackgroundSprite->setOrigin(mBackgroundSprite->getLocalBounds().size / 2.f);

    // Set ExitDoor to null at the start
    mExitDoor = nullptr;
}

cBaseLevel::~cBaseLevel()
{
    CleanupColliders();
}

void cBaseLevel::Update(float _DeltaTime)
{
    if (mExitDoor != nullptr)
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
    if (mExitDoor != nullptr)
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
    // Only draw door if it exists
    if (mExitDoor != nullptr)
    {
        mExitDoor->DebugDraw(mRenderWindow);
    }
}

void cBaseLevel::AddFullWallToList(cFullWall* _FullWall)
{
    // Add colider to vector list
	mFullWallColliders.push_back(_FullWall);
}

void cBaseLevel::AddHalfWallToList(cHalfWall* _HalfWall)
{
    std::cout << "Added half wall to list!" << std::endl;
    // Add colider to vector list
	mHalfWallColliders.push_back(_HalfWall);
}

void cBaseLevel::AddExitDoorToLevel(cExitDoor* _ExitDoor)
{
    mExitDoor = _ExitDoor;
}

void cBaseLevel::CleanupColliders()
{
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

    // Delete the background sprite
    delete mBackgroundSprite;
}

std::vector<cFullWall*>& cBaseLevel::GetFullWallColliderList()
{
    return mFullWallColliders;
}

std::vector<cHalfWall*>& cBaseLevel::GetHalfWallColliderList()
{
    return mHalfWallColliders;
}

cExitDoor* cBaseLevel::GetExitDoor()
{
    return mExitDoor;
}

void cBaseLevel::SaveLevel(cFileInterface& _FileInterface)
{
    // Get file interface to save level here
    _FileInterface.SaveLevelDialog();
}

void cBaseLevel::LoadLevel(cFileInterface& _FileInterface)
{
    // Get file interface to load level here
    _FileInterface.LoadLevelDialog();
}
