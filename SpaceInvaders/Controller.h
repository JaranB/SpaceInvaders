#pragma once
#include "SDL.h"
#include "Window.h"
#include <memory>
#undef main

class Controller
{
public:
	Controller();
	void GameLoop();
	void KeyDown();
	void StartGame();
	void Update();
	~Controller();

protected:
	Uint8 * keys;
	std::unique_ptr<Uint8> oldKeys;
	int keyCount;
	const Uint8 *state;
	bool running;
	Window window;
};

