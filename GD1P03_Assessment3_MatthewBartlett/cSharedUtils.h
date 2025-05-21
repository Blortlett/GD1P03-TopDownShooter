#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cSharedUtils
{
private:
	cSharedUtils();
	~cSharedUtils() {}

public:
	// Textures
	sf::Texture mBulletTex;



	// Static Functions
	static void NormalizeVector(sf::Vector2f& _VectorToNormalize)
	{
		float magnitude = std::sqrt(_VectorToNormalize.x * _VectorToNormalize.x +
			_VectorToNormalize.y * _VectorToNormalize.y);
		if (magnitude > 0.0f)
		{
			_VectorToNormalize /= magnitude;
		}
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