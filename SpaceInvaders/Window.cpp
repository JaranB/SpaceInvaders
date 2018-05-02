#include "stdafx.h"
#include "Window.h"
#include "InputManager.h"
#include <iostream>


Window::Window()
{ }


Window::~Window()
{}

void Window::loadWindow() {

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == nullptr)
	{
		std::cerr << "Failed to create window: "
			<< SDL_GetError() << std::endl;
		SDL_Quit();
	}

	if (renderer == nullptr)
	{
		std::cerr << "Failed to create renderer: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(window); SDL_Quit();
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}