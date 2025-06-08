#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>


class cSharedUtils
{
private:
	cSharedUtils();
	~cSharedUtils() {}

public:
	// -= Textures =-
	// Weapons
	sf::Texture mBulletTex;
	sf::Texture mPistolTex;
	// Doors
	sf::Texture mExitDoorTex;
	// Menu Background
	sf::Texture mStarBackground;

	// Fonts
	sf::Font mTitleFont;
	sf::Font mSubTitleFont;
	sf::Font mButtonFont;


	// Static Util Functions
	static void NormalizeVector(sf::Vector2f& _VectorToNormalize)
	{
		float magnitude = std::sqrt(_VectorToNormalize.x * _VectorToNormalize.x +
			_VectorToNormalize.y * _VectorToNormalize.y);
		if (magnitude > 0.0f)
		{
			_VectorToNormalize /= magnitude;
		}
	}

	static sf::Vector2f calculatePointFromOrigin(sf::Vector2f _Origin, float _Distance, sf::Angle& _Angle) {
		// Convert angle from degrees to radians
		//float angleRadians = angleDegrees * (M_PI / 180.0f);

		// Trig to calculate new position
		float x = _Origin.x + _Distance * std::cos(_Angle.asRadians());
		float y = _Origin.y + _Distance * std::sin(_Angle.asRadians());

		return sf::Vector2f(x, y);
	}


	// Singleton crap....
	// Get the single instance of the class
	static cSharedUtils& GetInstance()
	{
		static cSharedUtils instance; // Static instance created on first call
		return instance;
	}
	// Delete copy constructor and assignment operator to prevent copying
	cSharedUtils(const cSharedUtils&) = delete;
	cSharedUtils& operator=(const cSharedUtils&) = delete;
};