#pragma once
#include "cProjectileManager.h"
#include "cLevelProgressTracker.h"

class cLevelManager;
class cEnemyManager;

class cGameStateManager {
private:
    cEnemyManager& mEnemyManager;
    cProjectileManager& mProjectileManager;
    cLevelManager& mLevelManager;

    bool mLevelComplete = false;

public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager);
    void CheckBulletCollision();
    void InitializeLevelEnemies();
    bool IsLevelComplete() const { return mLevelComplete; }
};