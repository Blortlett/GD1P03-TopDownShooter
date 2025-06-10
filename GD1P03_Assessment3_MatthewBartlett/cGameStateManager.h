#pragma once
#include "cProjectileManager.h"
#include "cLevelProgressTracker.h"

class cLevelManager;
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

public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager, cPlayerCharacter& mPlayerCharacter, cPickupManager& _PickupManager);

    void Update(float _DeltaTime);

    // Collision
    void CheckBulletCollision();
    void CheckEnemyWallCollision();

    // Level Tracking
    void TransitionToNextLevel();
    bool IsLevelComplete() const { return mLevelComplete; }

    // Reset level function
    void CheckResetLevel(float _DeltaTime);
};