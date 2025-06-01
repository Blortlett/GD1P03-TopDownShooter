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
}

cBaseLevel::~cBaseLevel()
{
    CleanupColliders();
}

void cBaseLevel::Draw()
{
    if (!mBackgroundSprite) return;
    mRenderWindow.draw(*mBackgroundSprite);
}

void cBaseLevel::DebugDraw()
{
    // Draw all widgets for full wall colliders
    for (cFullWall* wall : mFullWallColliders)
    {
        wall->DebugDraw(mRenderWindow);
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
