#pragma once
#include "SDL.h"

class CEntity
{
public:
	CEntity(const char* bmpPath);
	~CEntity();

	void loadEntity(SDL_Window* vindu, SDL_Renderer* render);

	bool isAlive = true;

	SDL_Texture* entityDrawable;
	SDL_Rect entityCoords;
	SDL_Surface* entity;

	const char* m_bmpPath;
};