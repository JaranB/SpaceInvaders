#pragma once
#include "Window.h"

class NPC
{
public:
	NPC(int npcSpawnPositionX, int npcSpawnPositionY, int npcType);
	~NPC();

	void loadNPC(SDL_Window* vindu, SDL_Renderer* render);
	void setXCoord(int xCoord);
	void setYCoord(int yCoord);
	void setCoords(int xCoord, int yCoord);

	void moveRight();

	void setNpcType(int npcType);
	int getNpcType();

	int getXCoord();
	int getYCoord();

	SDL_Texture* NPCDrawable;
	SDL_Rect NPCCoords;
	SDL_Surface* NPCSurface;

protected:
	int m_npcType;
};

