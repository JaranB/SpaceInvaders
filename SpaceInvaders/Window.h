#pragma once
#include <SDL.h>
#undef main

class Window
{
public:
	Window();
	void loadWindow();
	void draw(SDL_Texture* texture, SDL_Rect coords);
	~Window();

	SDL_Window* window2;
	SDL_Renderer* renderer;
	SDL_Texture* spaceShipDrawable;
	SDL_Rect spaceShipCoords;
	SDL_Surface* spaceShip;

private:

};