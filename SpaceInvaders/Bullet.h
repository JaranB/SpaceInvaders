#ifndef BULLET_H
#define BULLET_H

#pragma once
#include "SDL.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void loadBullet(SDL_Window* vindu, SDL_Renderer* render, int x, int y);
	void bulletMovement();

	bool isAlive = false;

	SDL_Texture* bulletDrawable;
	SDL_Rect bulletCoords;
	SDL_Surface* bullet;
};

#endif