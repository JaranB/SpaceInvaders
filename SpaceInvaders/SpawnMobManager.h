#pragma once
#include "Window.h"
#include <vector>
#include "NPC.h"

class EntityManager
{
public:
	EntityManager(Window *window);
	~EntityManager();
	void AddNPCS();
	void loadNPCS();
	void drawNPCS();

protected:
	Window *m_window;
	int npcSpawnPositionY = 50;
	int npcSpawnPositionX = 400;
	std::vector<NPC> npcs;
};

