/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEventSystem]
Description : [This class is not used, but is a nice idea and I want to implement this stuff between my game managers to decouple stuff - save my ass from circular hell]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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