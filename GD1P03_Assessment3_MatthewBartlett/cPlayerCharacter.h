/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerCharacter]
Description : [This class functions as the player controller]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerInput.h"
#include "cPlayerAnimator.h"
#include "cPlayerAnimatorLegs.h"
#include "cCharacter.h"

class cProjectileManager;

class cPlayerCharacter : public cCharacter
{
private:
	// Constant Movement Values
	const float PLAYER_ACCELERATION = 700.f;
	const float PLAYER_MAX_VELOCITY = 200.f;
	const float PLAYER_FRICTION = .005f;

	// Input stuff
	void HandleInput();
	cPlayerInput& mPlayerInput;
	sf::Vector2f mPlayerInputNormalized;
	//Rotation stuff
	sf::Angle mPlayerLookDirection;
	void GetLookTowardsDirection();

	// Shooting
	void UpdateWeapon(float _DeltaSeconds) override;

	// Animator
	cPlayerAnimator mPlayerUpperBodyAnimator;
	cPlayerAnimatorLegs mPlayerLegsAnimator;

	// Camera Reference
	sf::View& mCameraView;

public:
	cPlayerCharacter(sf::Vector2f _StartPosition, cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, sf::View& _PlayerCamera, cPlayerInput& _PlayerInput);
	~cPlayerCharacter() {}
	
	// ResetPlayer after death
	void RevivePlayer();

	// Collision
	void OnCollision(sf::Vector2f direction); // Wall collision
	void OnBulletCollision(sf::Vector2f direction);

	// Draw / Update
	void Update(float _DeltaSeconds);
	void Draw();

	// Getters
	sf::Vector2f GetPosition() { return mPosition; }
	cBoxCollider& GetCollider() { return mBoxCollider; }

	// Setters
	void SetPosition(sf::Vector2f _Position);
};