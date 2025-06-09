#include "cWallBase.h"

cWallBase::cWallBase(sf::FloatRect _Bounds, sf::Color _Color)
	: mCollider(_Bounds)
	, mDebugWidget(mCollider, _Color)
{

}

void cWallBase::CheckCollideWithPlayer(cCharacter& character, sf::Vector2f& collisionDirection)
{
	// Check wall collision with player
	if (mCollider.CheckCollision(character.GetCollider(), collisionDirection, 1.0f))
	{
		// If collision, tell player object:
		character.OnCollision(collisionDirection);
	}
}

void cWallBase::DebugDraw(sf::RenderWindow& _Window)
{
	mDebugWidget.DrawWidget(_Window);
}

sf::FloatRect cWallBase::GetBounds()
{
	return mCollider.GetBounds();
}

bool cWallBase::CheckCollideWithPoint(sf::Vector2f point)
{
	sf::Vector2f newPoint = point;
	newPoint += mCollider.GetHalfSize();
	return mCollider.CheckCollisionPoint(newPoint);
}