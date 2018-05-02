#pragma once
#include "SDL.h"

class Player
{
public:
	Player();
	~Player();
	void loadShip(SDL_Window* vindu, SDL_Renderer* render);

	SDL_Texture* spaceShipDrawable;
	SDL_Rect spaceShipCoords;
	SDL_Surface* spaceShip;

private:
};

