/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAudioManager]
Description : [This singleton class loads and plays all music and sound effects for easy use]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <iostream>
#include <SFML/Audio.hpp>

class cAudioManager
{
private:
	// Private constructor for singleton access
	cAudioManager();
	~cAudioManager();

	// Music tracks
	sf::Music* CurrentMusic; // Music state
	sf::Music MenuMusic;
	sf::Music MusicLevel;
	
	// Sound Effects
	//Buffers
	sf::SoundBuffer mShootSFXBuffer;
	sf::SoundBuffer mDryFireSFXBuffer;
	sf::SoundBuffer mPistolRackSFXBuffer;

	// Sounds
	sf::Sound* mShootSound;
	sf::Sound* mDryFireSound;
	sf::Sound* mPistolRackSound;

	// Volumes / mutes
	float MusicVolume = 30.f;
	float SFXVolume = 90.f;
	bool IsMusicMuted = false;
	bool IsSFXMuted = false;

	//Level Count
	int LevelCount = 1;

	// music tracker bools
	bool mIsMenuMusicPlaying = false;
	bool mIsGameMusicPlaying = false;

public:
	// Get the single instance of the class
	static cAudioManager& GetInstance()
	{
		static cAudioManager instance; // Static instance created on first call
		return instance;
	}

	//   -= SFX FUNCTIONS =-
	// Play Sound Effects functions
	void SFXPlayShoot();
	void SFXPlayDryFire();
	void SFXPlayPistolRack();


	//   -= MUSIC FUNCTIONS =-
	// Swap Tunes
	void PlayMenuMusic();
	void PlayLevelMusic();

	// Pause/Play music
	void StopMusic();
	void ResumeMusic();

	// Mute sounds
	void MuteMusic(); // Toggle
	void MuteMusic(bool mute); // specific set
	void MuteSFX(); // Toggle
	void MuteSFX(bool mute); // Specific set
};