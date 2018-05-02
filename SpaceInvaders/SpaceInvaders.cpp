// SpaceInvaders.cpp : Defines the entry point for the console application.
//
#include <SDL.h>
#undef main
#include "stdafx.h"
#include "SpaceInvaders.h"
//#include "InputManager.h"
#include <iostream>

SpaceInvaders::SpaceInvaders()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 950, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//	InputManager inp;

	if (window == nullptr) {
		std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	if (renderer == nullptr) {
		std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	SDL_Surface* def = SDL_LoadBMP("default.bmp");

	if (def == nullptr) {
		std::cerr << "Failed to load image: " << SDL_GetError() << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	SDL_Texture* defDrawable = SDL_CreateTextureFromSurface(renderer, def);

	SDL_Rect defPos;
	defPos.h = def->h;
	defPos.h = def->w;
	defPos.x = 10;
	defPos.x = 10;

	SDL_FreeSurface(def);
}


SpaceInvaders::~SpaceInvaders()
{
}