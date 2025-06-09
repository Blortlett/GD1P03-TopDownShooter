#pragma once
#include "cProjectileManager.h"
#include "cLevelProgressTracker.h"

class cLevelManager;
class cEnemyManager;
class cPlayerCharacter;

class cGameStateManager {
private:
    cEnemyManager& mEnemyManager;
    cProjectileManager& mProjectileManager;
    cLevelManager& mLevelManager;
    cPlayerCharacter& mPlayerCharacter;

    bool mLevelComplete = false;

    void InitializeLevelEnemies();

    // Death screen timer
    float const mPlayerDeathTimerMax = 2.f;
    float mPlayerDeathTimer = mPlayerDeathTimerMax;

public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager, cPlayerCharacter& mPlayerCharacter);
    void CheckBulletCollision();
    void TransitionToNextLevel();
    bool IsLevelComplete() const { return mLevelComplete; }

    // Reset level function
    void CheckResetLevel(float _DeltaTime);
};