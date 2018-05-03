#pragma once
#include <SDL.h>
#undef main

class Window
{
public:
	Window();
	void loadWindow();
	void draw(SDL_Texture* texture, SDL_Rect coords);
	void renderClear();
	~Window();

	SDL_Window* gameWindow;
	SDL_Renderer* renderer;
	SDL_Texture* spaceShipDrawable;
	SDL_Rect spaceShipCoords;
	SDL_Surface* spaceShip;

private:

};