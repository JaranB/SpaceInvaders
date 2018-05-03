#include "stdafx.h"
#include "SpawnMobManager.h"


EntityManager::EntityManager(Window *gameWindow)
{
	m_window = gameWindow;
}


EntityManager::~EntityManager()
{}

void EntityManager::AddNPCS() {

	for (int i = 0; i < 8; i++) {
		NPC npc(npcSpawnPositionX, npcSpawnPositionY, 1);
		npcs.push_back(npc);
		npcSpawnPositionX += 70;
	}

	npcSpawnPositionY += 60;
	npcSpawnPositionX = 400;

	for (int i = 0; i < 8; i++) {
		NPC npc(npcSpawnPositionX, npcSpawnPositionY, 2);
		npcs.push_back(npc);
		npcSpawnPositionX += 70;
	}

	npcSpawnPositionY += 50;
	npcSpawnPositionX = 400;

	for (int i = 0; i < 8; i++) {
		NPC npc(npcSpawnPositionX, npcSpawnPositionY, 3);
		npcs.push_back(npc);
		npcSpawnPositionX += 70;
	}

	npcSpawnPositionY += 50;
	npcSpawnPositionX = 400;

	for (int i = 0; i < 8; i++) {
		NPC npc(npcSpawnPositionX, npcSpawnPositionY, 4);
		npcs.push_back(npc);
		npcSpawnPositionX += 70;
	}

	loadNPCS();
}

void EntityManager::loadNPCS() {

	std::vector<NPC>::iterator it;

	for (it = npcs.begin(); it != npcs.end(); it++) {
		it->loadNPC(m_window->gameWindow, m_window->renderer);
	}
}

void EntityManager::drawNPCS() {

	std::vector<NPC>::iterator it;

	for (it = npcs.begin(); it != npcs.end(); it++) {
		m_window->draw(it->NPCDrawable, it->NPCCoords);
		it->moveRight();
	}
}