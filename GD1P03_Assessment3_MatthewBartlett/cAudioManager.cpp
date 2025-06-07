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
	, JumpSound(nullptr)
{
	// Buffers
	JumpBuffer.loadFromFile("Assets/Audio/SFX/jump.wav");

	// Sounds
	JumpSound = new sf::Sound(JumpBuffer);

	JumpSound->setVolume(35.f);


	// Music
	MenuMusic.openFromFile("Assets/Audio/Music/admiralbob77_-_Laying_Low_6.mp3");
	MusicLevel.openFromFile("Slumlord-Chillin-Waiting.ogg");

	MenuMusic.setLooping(true);
	MusicLevel.setLooping(true);

	PlayMenuMusic();
}

cAudioManager::~cAudioManager()
{
	delete JumpSound;
}

void cAudioManager::SFXPlayJump()
{
	JumpSound->play();
}

void cAudioManager::PlayMenuMusic()
{
	if (IsMusicMuted) return; // Dont bother if music is muted
	StopMusic();
	CurrentMusic = &MenuMusic;
	CurrentMusic->setVolume(MusicVolume);
	CurrentMusic->play();
}

void cAudioManager::PlayLevelMusic()
{
	StopMusic();
	CurrentMusic = &MusicLevel;
	CurrentMusic->setVolume(MusicVolume);
	CurrentMusic->play();
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