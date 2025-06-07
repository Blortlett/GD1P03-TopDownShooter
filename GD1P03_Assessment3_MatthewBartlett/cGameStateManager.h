#pragma once
#include "cEnemyManager.h"
#include "cProjectileManager.h"
#include "cLevelProgressTracker.h"
#include "cLevelManager.h"

class cGameStateManager {
private:
    cEnemyManager& mEnemyManager;
    cProjectileManager& mProjectileManager;
    cLevelManager& mLevelManager;

    bool mLevelComplete = false;

public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager);
    void TrackLevelComplete();
    void CheckBulletCollision();
    bool IsLevelComplete() const { return mLevelComplete; }
};