#pragma once
#include <SDL.h>
#undef main

class Window
{
public:
	Window();
	void loadWindow();
	~Window();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};