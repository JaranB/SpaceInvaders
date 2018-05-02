#pragma once
#include "Window.h"

class NPC
{
public:
	NPC(int xCoord, int yCoord);
	~NPC();

	void loadNPC(SDL_Window* vindu, SDL_Renderer* render);
	void setXCoord(int xCoord);
	void setYCoord(int yCoord);
	void setCoords(int xCoord, int yCoord);

	int getXCoord();
	int getYCoord();

	SDL_Texture* NPCDrawable;
	SDL_Rect NPCCoords;
	SDL_Surface* NPCSurface;
};

