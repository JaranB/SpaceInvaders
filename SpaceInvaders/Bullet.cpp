#include "stdafx.h"
#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{

}


Bullet::~Bullet()
{
}

void Bullet::loadBullet(SDL_Window* vindu, SDL_Renderer* render, int x, int y) {
	bullet = SDL_LoadBMP("./resources/laser.bmp");

	if (bullet == nullptr)
	{
		std::cerr << "Failed to load image: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyRenderer(render); SDL_DestroyWindow(vindu); SDL_Quit();
	}

	bulletDrawable = SDL_CreateTextureFromSurface(render, bullet);

	bulletCoords.h = bullet->h;
	bulletCoords.w = bullet->w;
	bulletCoords.x = x + 20;
	bulletCoords.y = y - 10;

	SDL_FreeSurface(bullet);
}

void Bullet::bulletMovement() {
	if (bulletCoords.y == 0) {
		SDL_DestroyTexture(bulletDrawable);
		bulletDrawable = nullptr;
		isAlive = false;
	}
	else {
		bulletCoords.y = bulletCoords.y - 1;
	}
}