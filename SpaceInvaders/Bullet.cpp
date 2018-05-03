#include "stdafx.h"
#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	m_bmpPath = bmpPath;
}

Bullet::~Bullet()
{
}

void Bullet::bulletMovement() {
	if (entityCoords.y == 0) {
		SDL_DestroyTexture(entityDrawable);
		entityDrawable = nullptr;
		isAlive = false;
	}
	else {
		entityCoords.y = entityCoords.y - 1;
	}
}