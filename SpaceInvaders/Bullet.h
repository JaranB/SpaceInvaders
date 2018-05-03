#ifndef BULLET_H
#define BULLET_H

#pragma once
#include "SDL.h"
#include "CEntity.h"

class Bullet : public CEntity
{
public:
	Bullet();
	~Bullet();

	const char* bmpPath = "./resources/laser.bmp";

	void bulletMovement();
};

#endif