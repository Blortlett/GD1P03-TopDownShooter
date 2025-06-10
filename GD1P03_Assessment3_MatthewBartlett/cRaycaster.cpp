#include "cRaycaster.h"
#include "cCharacter.h"
#include "cLevelProgressTracker.h"
#include "cFullWall.h"
#include "cSharedUtils.h"

cRaycaster::cRaycaster(cCharacter& _Detectable)
	: mCharacter(_Detectable)
	, mLevelWalls(cLevelProgressTracker::GetInstance().GetWallVector())
{
	// Setup debug line
	mDebugLine.setFillColor(sf::Color::Magenta);
	mDebugLine.setSize({ mCastDistance, .5f });
	mDebugLine.setOrigin({ 0.f ,mDebugLine.getSize().y / 2.f });
}

bool cRaycaster::Cast(sf::Vector2f _Origin, sf::Angle _Angle)
{
	// Set debug gfx
	mDebugLine.setPosition(_Origin);
	mDebugLine.setRotation(_Angle);

	// Begin cast
	bool hit = false;
	mCurrentCastDist = 30.f;		// Start a bit away from character to save some calculation
	while (mCurrentCastDist <= mCastDistance)
	{
		sf::Vector2f castPoint = cSharedUtils::GetInstance().calculatePointFromOrigin(_Origin, mCurrentCastDist, _Angle);

		// Check against each wall
		for (cFullWall* Wall : *mLevelWalls)
		{
			hit = Wall->CheckCollideWithPoint(castPoint);
			// If wall found, return false early
			if (hit) return false;
		}

		// If no wall collision, check against player
		hit = mCharacter.GetCollider().CheckCollisionPoint(castPoint);
		// If player found - Return true for successful detection
		if (hit)
		{
			return true;
		}
		// If nothing found - increment cast distance
		mCurrentCastDist += mCastIncremement;
	}

	
	// No wall found return false
	return false;
}

void cRaycaster::DebugDraw(sf::RenderWindow& _Window)
{
	_Window.draw(mDebugLine);
}
