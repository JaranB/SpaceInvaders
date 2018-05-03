#include "stdafx.h"
#include "CEntity.h"
#include <iostream>


CEntity::CEntity()
{
}


CEntity::~CEntity()
{
}

void CEntity::loadEntity(SDL_Window* vindu, SDL_Renderer* render, int x, int y) {
	entity = SDL_LoadBMP(m_bmpPath);

	if (entity == nullptr)
	{
		std::cerr << "Failed to load image: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyRenderer(render); SDL_DestroyWindow(vindu); SDL_Quit();
	}

	entityDrawable = SDL_CreateTextureFromSurface(render, entity);

	entityCoords.h = entity->h;
	entityCoords.w = entity->w;
	entityCoords.x = x;
	entityCoords.y = y;

	SDL_FreeSurface(entity);
}