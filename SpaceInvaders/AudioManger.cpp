#include "stdafx.h"
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "AudioManager.h"
#include "Controller.h"

int int main(int argc, char* argv[])
{
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_Chunk *soundEffect = NULL;
	soundEffect = Mix_LoadWAV("laser.wav");
	Mix_PlayChannel(-1, soundEffect, 0);

	Mix_Music *music = NULL;
	music = Mix_LoadMUS("beat.wav");
	Mix_PlayMusic(music, -1);
}

void PauseMusic()
{
	Mix_PauseMusic();
}

void ResumeMusic()
{
	
}

void ReleaseMusic()
{
	Mix_CloseAudio();
	Mix_Quit();
}