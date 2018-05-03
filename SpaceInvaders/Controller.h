#pragma once
#include "SDL.h"
#include "Window.h"
#include "Player.h"
#include <memory>
#include "vector"
#include "NPC.h"
#include "Bullet.h"
#include "EntityManager.h"

#undef main

class Controller
{
public:
	Controller();
	void GameLoop();
	void KeyDown();
	void StartGame();
	void Update();
	void AddNPCS();
	void loadNPCS();
	void drawNPCS();
	~Controller();

protected:
	Uint8 * keys;
	std::unique_ptr<Uint8> oldKeys;
	int keyCount;
	int npcSpawnPositionY = 50;
	int npcSpawnPositionX = 400;
	const Uint8 *state;
	bool running;
	Window window;
	Player player;
	std::vector<NPC> npcs;
	Bullet bullet;
	EntityManager *entityManager;
};
