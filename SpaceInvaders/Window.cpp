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
	gameWindow = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

	if (gameWindow == nullptr)
	{
		std::cerr << "Failed to create window: "
			<< SDL_GetError() << std::endl;
		SDL_Quit();
	}

	if (renderer == nullptr)
	{
		std::cerr << "Failed to create renderer: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(gameWindow); SDL_Quit();
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Window::draw(SDL_Texture* texture, SDL_Rect coords) {

	SDL_RenderCopy(renderer, texture, nullptr, &coords);
}

void Window::renderClear() {
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}