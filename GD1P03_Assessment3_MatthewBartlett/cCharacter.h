#pragma once
#include "cDebugWidget.h"
#include "cAnimatorBase.h"
#include "cBoxCollider.h"
#include "cPistol.h"

class cCharacter
{
protected:
	// Constant Movement Values
	const float PLAYER_ACCELERATION = 700.f;
	const float PLAYER_MAX_VELOCITY = 200.f;
	const float PLAYER_FRICTION = .005f;

	// Control Values
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;

	// Rotate Function
	void Rotate(sf::Vector2f _FaceTowards);
	void Rotate(sf::Angle _FaceTowards);
	// Movement Function
	void Move(sf::Vector2f _NormalizedDirection, float _DeltaSeconds);

	// Weapon Stuff
	cPistol mPistol;
	bool mIsShooting = false;
	virtual void UpdateWeapon(float _DeltaSeconds) = 0;

	// Spawn point
	sf::Vector2f mSpawnPoint;

	// Animator
	cAnimatorBase* mCharacterAnimator;
	cAnimatorBase* mCharacterAnimatorBottom;

	// Collision
	cBoxCollider mBoxCollider;

	// App/Gamemanager Stuff
	sf::RenderWindow& mRenderWindow;

	// Debug Stuff
	cDebugWidget mDebugWidget;

public:
	cCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, bool _IsPlayer);
	~cCharacter() {}

	// Respawn Character
	void RespawnCharacter();

	// Collision
	void OnCollision(sf::Vector2f direction);

	// Draw / Update()
	virtual void Update(float _DeltaSeconds) = 0;
	void Draw();

	// Getters
	sf::Vector2f GetPosition() { return mPosition; }
	cBoxCollider& GetCollider() { return mBoxCollider; }
};