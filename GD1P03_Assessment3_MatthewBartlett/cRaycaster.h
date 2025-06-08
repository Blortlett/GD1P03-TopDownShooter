#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class cCharacter;
class cFullWall;

class cRaycaster
{
private:
	//sf::Vector2f mOrigin;
	//sf::Vector2f mDirection;
	float const mCastDistance = 250.f;
	float mCastIncremement = 10.f;
	float mCurrentCastDist = 0.f;
	sf::RectangleShape mDebugLine;

	// Player Character Reference - Detectable
	cCharacter& mCharacter;
	// Walls to check against - Detectable
	std::vector<cFullWall*>* mLevelWalls;

public:
	cRaycaster(cCharacter& _Detectable);
	~cRaycaster() {}

	bool Cast(sf::Vector2f _Origin, sf::Angle _Angle);
	void DebugDraw(sf::RenderWindow& _Window);
};