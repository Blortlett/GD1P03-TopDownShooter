#pragma once
#include "cWallBase.h"

class cExitDoor : public cWallBase
{
private:
	sf::Sprite mDoorSprite;

	// Set IsDoorOpenFull to true when finished opening
	bool mIsDoorOpenFull = false;

	// How far the door should open (to the left)
	float mDoorOpenAmount = 84.f;
	float const mOpenSpeedModifier = 30.f;

public:
	cExitDoor(sf::Vector2f _StartPosition);
	~cExitDoor() {}

	// Set position
	void SetPosition(sf::Vector2f _Position) { mCollider.MoveColliderPosition(_Position); }

	// I guess we gotta call something every frame
	void Update(float _DeltaTime);
	void Draw(sf::RenderWindow& _Window);

	// getters
	sf::Vector2f GetPosition();
};