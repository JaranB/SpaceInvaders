#include "stdafx.h"
#include "Player.h"
#include "SDL.h"
#include "InputManager.h"
#include <iostream>

Player::Player()
{
}


Player::~Player()
{
	
}

void Player::loadShip(SDL_Window* vindu, SDL_Renderer* render) {
	spaceShip = SDL_LoadBMP("./resources/ship.bmp");

	if (spaceShip == nullptr)
	{
		std::cerr << "Failed to load image: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyRenderer(render); SDL_DestroyWindow(vindu); SDL_Quit();
	}

	spaceShipDrawable = SDL_CreateTextureFromSurface(render, spaceShip);

	spaceShipCoords.h = spaceShip->h;
	spaceShipCoords.w = spaceShip->w;
	spaceShipCoords.x = 400;
	spaceShipCoords.y = 850;

	SDL_FreeSurface(spaceShip);
}