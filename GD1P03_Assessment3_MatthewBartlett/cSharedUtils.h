#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>


class cSharedUtils
{
private:
	cSharedUtils();
	~cSharedUtils() {}

public:
	// -= Textures =-
	// UI
	sf::Texture mUIBulletFullTex;
	sf::Texture mUIBulletEmptyTex;
	sf::Texture mUIArrow;

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


	// -= Static Util Functions =-
	static void NormalizeVector(sf::Vector2f& _VectorToNormalize)
	{
		float magnitude = std::sqrt(_VectorToNormalize.x * _VectorToNormalize.x +
			_VectorToNormalize.y * _VectorToNormalize.y);
		if (magnitude > 0.0f)
		{
			_VectorToNormalize /= magnitude;
		}
	}

	static float NormalizeAngle(float angle) {
		const float TWO_PI = 6.28318530718f;
		angle = fmod(angle, TWO_PI); // Wrap angle to [0, 2pi)
		if (angle < 0) angle += TWO_PI; // Handle negative angles
		return angle;
	}

	static sf::Vector2f calculatePointFromOrigin(sf::Vector2f _Origin, float _Distance, sf::Angle& _Angle) {
		// Trig to calculate new position
		float x = _Origin.x + _Distance * std::cos(_Angle.asRadians());
		float y = _Origin.y + _Distance * std::sin(_Angle.asRadians());

		return sf::Vector2f(x, y);
	}

	static sf::Angle GetLookTowardsAngle(sf::Vector2f _StartPos, sf::Vector2f _EndPos) {
		// Calculate position difference
		float dx = _EndPos.x - _StartPos.x;
		float dy = _EndPos.y - _StartPos.y;

		// Calculate the angle
		sf::Angle angle = sf::radians(std::atan2(dy, dx));

		return angle;
	}

	static float ShortestAngleDiff(float angle1, float angle2) {
		const float TWO_PI = 6.28318530718f;
		float diff = angle1 - angle2;
		// Normalize difference to [-pi, pi]
		diff = fmod(diff + 3.1415926535f, TWO_PI) - 3.1415926535f;
		return diff;
	}

	static void Magnitude(sf::Vector2f& _DistanceVector, float& _ReturnValue)
	{
		_ReturnValue = std::sqrt(_DistanceVector.x * _DistanceVector.x + _DistanceVector.y * _DistanceVector.y);
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