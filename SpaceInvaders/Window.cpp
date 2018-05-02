#include "stdafx.h"
#include "Window.h"
#include <iostream>


Window::Window()
{ }


Window::~Window()
{}

void Window::loadWindow() {

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("C++", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 340, 340, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
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

	while (true) {
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}

}