#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "SDL.h"
#include "CEntity.h"
#include <string>

class Player : public CEntity
{
public:
	Player();
	~Player();

	int playerLives = 3;

	const char* bmpPath = "./resources/ship.bmp";

private:
};

#endif