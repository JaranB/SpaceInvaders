#pragma once
#include "Window.h"

class Player
{
public:
	Player();
	~Player();
	void loadShip(SDL_Window* vindu, SDL_Renderer* render);

	int laserDmg = 10;

	SDL_Texture* spaceShipDrawable;
	SDL_Rect spaceShipCoords;
	SDL_Surface* spaceShip;

private:
	Window window;

};

