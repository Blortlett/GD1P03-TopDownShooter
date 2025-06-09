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
#include "cAudioManager.h"

cAudioManager::cAudioManager()
	: CurrentMusic(nullptr)
	, mShootSound(nullptr)
{
	// -= SFX =-
	// Buffers
	mShootSFXBuffer.loadFromFile("Assets/Audio/SFX/Gun/9mm Single.wav");
	mDryFireSFXBuffer.loadFromFile("Assets/Audio/SFX/Gun/9mm Pistol Dry Fire.wav");
	mPistolRackSFXBuffer.loadFromFile("Assets/Audio/SFX/Gun/9mm Pistol Rack Full.wav");
	// Sounds
	mShootSound = new sf::Sound(mShootSFXBuffer);
	mDryFireSound = new sf::Sound(mDryFireSFXBuffer);
	mPistolRackSound = new sf::Sound(mPistolRackSFXBuffer);
	// SFX Volume
	mShootSound->setVolume(60.f);
	mDryFireSound->setVolume(80.f);
	mPistolRackSound->setVolume(80.f);


	// -= Music =-
	// Load Music
	MenuMusic.openFromFile("Assets/Audio/Music/admiralbob77_-_Laying_Low_6.mp3");
	MusicLevel.openFromFile("Assets/Audio/Music/Slumlord-Chillin-Waiting.ogg");
	// Set Looping
	MenuMusic.setLooping(true);
	MusicLevel.setLooping(true);
}

cAudioManager::~cAudioManager()
{
	delete mShootSound;
	delete mDryFireSound;
	delete mPistolRackSound;
}

void cAudioManager::SFXPlayShoot()
{
	mShootSound->play();
}

void cAudioManager::SFXPlayDryFire()
{
	mDryFireSound->play();
}

void cAudioManager::SFXPlayPistolRack()
{
	mPistolRackSound->play();
}

void cAudioManager::PlayMenuMusic()
{
	if (mIsMenuMusicPlaying) return; // if menu music playing, return. dont worry bout it
	if (IsMusicMuted) return; // Dont bother if music is muted
	StopMusic();
	CurrentMusic = &MenuMusic;
	CurrentMusic->setVolume(MusicVolume);
	CurrentMusic->play();
	mIsMenuMusicPlaying = true;
	mIsGameMusicPlaying = false;
}

void cAudioManager::PlayLevelMusic()
{
	if (mIsGameMusicPlaying) return; // if menu music playing, return. dont worry bout it
	if (IsMusicMuted) return; // Dont bother if music is muted
	StopMusic();
	CurrentMusic = &MusicLevel;
	CurrentMusic->setVolume(MusicVolume + 40.f);
	CurrentMusic->play();
	mIsGameMusicPlaying = true;
	mIsMenuMusicPlaying = false;
}

void cAudioManager::StopMusic()
{
	if (CurrentMusic) {
		CurrentMusic->stop();
	}
}

void cAudioManager::ResumeMusic()
{
	if (CurrentMusic) {
		CurrentMusic->play();
	}
}

void cAudioManager::MuteMusic(bool mute)
{
	IsMusicMuted = mute;
	if (CurrentMusic) {
		if (IsMusicMuted)
		{ // Stop music - its muted
			StopMusic();
		}
		else
		{ // Music unmuted - play those tunes
			ResumeMusic();
		}
	}
}

void cAudioManager::MuteSFX(bool mute)
{
	IsSFXMuted = mute;
}