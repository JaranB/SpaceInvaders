#pragma once
#include "SDL.h"
#include "Window.h"
#include "Player.h"
#include <memory>
#include "vector"
#include "NPC.h"
#undef main

class Controller
{
public:
	Controller();
	void GameLoop();
	void KeyDown();
	void StartGame();
	void Update();
	void AddNPC();
	void loadNPCS();
	void drawNPCS();
	~Controller();

protected:
	Uint8 * keys;
	std::unique_ptr<Uint8> oldKeys;
	int keyCount;
	const Uint8 *state;
	bool running;
	Window window;
	Player player;
	std::vector<NPC> npcs;
};
