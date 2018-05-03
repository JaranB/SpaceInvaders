#include "stdafx.h"
#include <iostream>
#include "SDL.h"
#include "AudioManager.h"

// Sound effect
Mix_Chunk *soundEffect = NULL;
// Background MUsic
Mix_Music *music = NULL;

AudioManager::AudioManager()
{}


AudioManager::~AudioManager()
{}

void AudioManager::LoadMixer() {
	if(SDL_Init(SDL_INIT_AUDIO) == -1)
	{
		std::cout << "Error Initalzing mixer" << Mix_GetError();
	}
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
}

void AudioManager::loadAudio()
{
	bool success = true;

	// load background music
	music = Mix_LoadMUS("bgm.wav");
	if (music == NULL)
	{
		std::cout << "Failed to in background music" << Mix_GetError();
		success = false;
	}

	// load sfx
	soundEffect = Mix_LoadWAV("laser.wav");
	if (soundEffect == NULL)
	{
		std::cout << "Failed to load in SFX" << Mix_GetError();
		success = false;
	}
}

void AudioManager::PlaySFX()
{
	if (Mix_PlayChannel(-1, soundEffect, 0) == -1)
	{
		std::cout << "Error loading SFX" << Mix_GetError();
	}
}

void AudioManager::PlayMusic()
{
	if (Mix_FadeInMusic(music, -1, 3500) == -1)
	{
		std::cout << "Error loading music" << Mix_GetError();
	}
}


void AudioManager::PauseMusic()
{

	Mix_PauseMusic();
}

void AudioManager::ResumeMusic()
{
	if (Mix_PausedMusic() == 1 )
	{
		Mix_ResumeMusic();
	}
}

void AudioManager::CleanUp()
{
	// Free sound effect and music
	Mix_FreeChunk(soundEffect);
	Mix_FreeMusic(music);

	// Close SDL
	Mix_CloseAudio();
	Mix_Quit();
}
