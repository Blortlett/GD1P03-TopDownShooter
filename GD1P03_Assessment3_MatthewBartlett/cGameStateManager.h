#pragma once
#include "cEnemyManager.h"
#include "cProjectileManager.h"
#include "cLevelProgressTracker.h"

class cGameStateManager {
private:
    cEnemyManager& mEnemyManager;
    cProjectileManager& mProjectileManager;

    bool mLevelComplete = false;

public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager);
    void TrackLevelComplete();
    void CheckBulletToEnemyCollision();
    bool IsLevelComplete() const { return mLevelComplete; }
};