// cEventSystem.h
#pragma once
#include <functional>
#include <map>
#include <string>
enum class EventType { PlayerMoved, BulletHitEnemy, LevelComplete, ToggleDebug };
class cEventSystem {
private:
    std::map<EventType, std::vector<std::function<void(void*)>>> mListeners;
public:
    void Subscribe(EventType _Type, std::function<void(void*)> _Callback);
    void Dispatch(EventType _Type, void* _Data);
};