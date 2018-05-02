#include "stdafx.h"
#include "NPC.h"
#include <iostream>


NPC::NPC(int xCoord, int yCoord)
{
	setCoords(xCoord, yCoord);
}


NPC::~NPC()
{

}

void NPC::setXCoord(int xCoord) {
	NPCCoords.x = xCoord;
}
void NPC::setYCoord(int yCoord) {
	NPCCoords.y = yCoord;
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

void NPC::loadNPC(SDL_Window* vindu, SDL_Renderer* render) {
	NPCSurface = SDL_LoadBMP("./resources/npc1.bmp");

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