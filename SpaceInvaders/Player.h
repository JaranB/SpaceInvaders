#pragma once
#include "SDL.h"
#include "CEntity.h"
#include <string>

class Player : public CEntity
{
public:
	Player(const char* bmpPath) : CEntity(bmpPath) {};
	~Player();

	int playerLives = 3;

	std::string bmpPath = "./resources/ship.bmp";

private:
};