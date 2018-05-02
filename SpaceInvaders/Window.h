#pragma once
#include <SDL.h>
#undef main

class Window
{
public:
	Window();
	void loadWindow();
	void loadShip();
	void drawShip();
	~Window();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface* spaceShip;
	SDL_Texture* spaceShipDrawable;
	SDL_Rect spaceShipSpawn;
};