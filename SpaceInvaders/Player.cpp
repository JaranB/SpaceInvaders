#include "stdafx.h"
#include "Player.h"
#include "SDL.h"
#include "InputManager.h"
#include <iostream>

Player::Player(const char* bmpPath) : CEntity(bmpPath)
{
	entityCoords.h = entity->h;
	entityCoords.w = entity->w;
	entityCoords.x = 400;
	entityCoords.y = 850;
}

Player::~Player()
{
	
}