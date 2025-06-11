#pragma once
#include "cProjectileManager.h"
#include "cLevelProgressTracker.h"
#include "cLevelManager.h"

//class cLevelManager;
class cEnemyManager;
class cPlayerCharacter;
class cPickupManager;

class cGameStateManager {
private:
    cEnemyManager& mEnemyManager;
    cProjectileManager& mProjectileManager;
    cLevelManager& mLevelManager;
    cPlayerCharacter& mPlayerCharacter;
    cPickupManager& mPickupManager;

    bool mLevelComplete = false;

    void InitializeLevelEnemies();

    // Death screen timer
    float const mPlayerDeathTimerMax = 2.f;
    float mPlayerDeathTimer = mPlayerDeathTimerMax;

    // Application manager stuff
    bool mIsGameRunning = false;

public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager, cPlayerCharacter& mPlayerCharacter, cPickupManager& _PickupManager);

    void Update(float _DeltaTime);

    // Unload levels
    void UnloadLevels();

    // Collision
    void CheckBulletCollision();
    void CheckEnemyWallCollision();

    // Level Tracking
    void TransitionToNextLevel();
    bool IsLevelComplete() const { return mLevelComplete; }

    // Reset level function
    void CheckResetLevel(float _DeltaTime);

    // Getters
    sf::Vector2f GetLevelExitPosition() { return mLevelManager.GetLevelExitPosition(); }
};