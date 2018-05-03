#include "stdafx.h"
#include "NPC.h"
#include <iostream>


NPC::NPC(int npcSpawnPositionX, int npcSpawnPositionY, int npcType)
{
	setCoords(npcSpawnPositionX, npcSpawnPositionY);
	setNpcType(npcType);
}


NPC::~NPC()
{

}

int NPC::getXCoord() {
	return NPCCoords.x;
}

int NPC::getYCoord() {
	return NPCCoords.y;
}

void NPC::setCoords(int xCoord, int yCoord) {
	NPCCoords.x = xCoord;
	NPCCoords.y = yCoord;
}

void NPC::setNpcType(int npcType) {
	m_npcType = npcType;
}

int NPC::getNpcType() {
	return m_npcType;
}

void NPC::loadNPC(SDL_Window* vindu, SDL_Renderer* render) {

	if (m_npcType == 1) {
		NPCSurface = SDL_LoadBMP("./resources/npc1.bmp");
	}
	else if (m_npcType == 2) {
		NPCSurface = SDL_LoadBMP("./resources/npc2.bmp");
	}
	else if (m_npcType == 3) {
		NPCSurface = SDL_LoadBMP("./resources/npc3.bmp");
	}
	else if (m_npcType == 4) {
		NPCSurface = SDL_LoadBMP("./resources/npc4.bmp");
	}

	std::cout << getNpcType();

	if (NPCSurface == nullptr)
	{
		std::cerr << "Failed to load image: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyRenderer(render); SDL_DestroyWindow(vindu); SDL_Quit();
	}

	NPCDrawable = SDL_CreateTextureFromSurface(render, NPCSurface);

	NPCCoords.h = NPCSurface->h;
	NPCCoords.w = NPCSurface->w;

	SDL_FreeSurface(NPCSurface);
}

void NPC::moveRight() {
	NPCCoords.x -= 1;
}