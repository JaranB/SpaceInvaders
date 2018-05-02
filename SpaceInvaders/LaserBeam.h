#pragma once
#include "SDL.h"

class LaserBeam
{
public:
	LaserBeam();
	~LaserBeam();
	void loadLaserBeam(SDL_Window* vindu, SDL_Renderer* render);

	SDL_Texture* texture;

	int speed = 10;
	int laserDmg = 10;

private:
	
};

