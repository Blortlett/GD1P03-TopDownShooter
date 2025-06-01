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
#include "cBoxCollider.h"
#include "cPlayerAnimator.h"
#include "cPistol.h"
#include "cDebugWidget.h"

class cProjectileManager;

class cPlayerCharacter
{
private:
	// Input stuff
	void HandleInput();
	cPlayerInput& mPlayerInput;
	sf::Vector2f mPlayerInputNormalized;

	// Rotation Stuff
	void Rotate();
	// Movement stuff
	void Move(float _DeltaSeconds);
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	// Constant Movement Values
	const float PLAYER_ACCELERATION = 700.f;
	const float PLAYER_MAX_VELOCITY = 200.f;
	const float PLAYER_FRICTION = .005f;

	// Shooting
	void UpdateWeapon();
	cPistol mPistol;
	bool mIsShooting = false;

	// Animators
	cPlayerAnimator mPlayerUpperBodyAnimator;

	// Collision
	sf::FloatRect mColliderBounds;
	cBoxCollider mBoxCollider;

	// App/Gamemanager Stuff
	sf::RenderWindow& mRenderWindow;
	// Camera Reference
	sf::View& mCameraView;

	// Debug Stuff
	cDebugWidget mDebugWidget;

public:
	cPlayerCharacter(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, sf::View& _PlayerCamera, cPlayerInput& _PlayerInput);
	~cPlayerCharacter() {}

	// Collision
	void OnCollision(sf::Vector2f direction);

	// Draw / Update
	void Update(float _DeltaSeconds);
	void Draw();

	// Getters
	sf::Vector2f GetPosition() { return mPosition; }
	cBoxCollider& GetCollider() { return mBoxCollider; }
};