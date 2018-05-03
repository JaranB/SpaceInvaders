#ifndef CENTITY_H
#define CENTITY_H

#pragma once
#include "SDL.h"

class CEntity
{
public:
	CEntity();
	~CEntity();

	void loadEntity(SDL_Window* vindu, SDL_Renderer* render, int x, int y);

	bool isAlive = true;

	SDL_Texture* entityDrawable;
	SDL_Rect entityCoords;
	SDL_Surface* entity;

	const char* m_bmpPath;
};

#endif