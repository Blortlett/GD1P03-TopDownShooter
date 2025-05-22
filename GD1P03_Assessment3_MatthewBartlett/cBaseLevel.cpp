#include "cBaseLevel.h"

cBaseLevel::cBaseLevel(sf::RenderWindow& _Window)
	: mRenderWindow(_Window)
{
}

cBaseLevel::~cBaseLevel()
{
    // Delete all full wall colliders
    for (cBoxCollider* collider : mFullWallColliders)
    {
        delete collider;
    }
    mFullWallColliders.clear();

    // Delete all half wall colliders
    for (cBoxCollider* collider : mHalfWallColliders)
    {
        delete collider;
    }
    mHalfWallColliders.clear();

    // Delete the background sprite
    delete mBackgroundSprite;
}

void cBaseLevel::DebugDraw()
{

}

void cBaseLevel::AddFullWallToList(cBoxCollider* _FullWall)
{
	mFullWallColliders.push_back(_FullWall);
}

void cBaseLevel::AddHalfWallToList(cBoxCollider* _HalfWall)
{
	mHalfWallColliders.push_back(_HalfWall);
}
