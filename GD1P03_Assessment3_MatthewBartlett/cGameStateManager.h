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
public:
    cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager, cPlayerCharacter& mPlayerCharacter);
    void CheckBulletCollision();
    void TransitionToNextLevel();
    bool IsLevelComplete() const { return mLevelComplete; }
};