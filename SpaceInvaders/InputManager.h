#pragma once
#include "SDL.h"
#include <memory>
#undef main

class InputManager
{
public:
	InputManager();
	~InputManager();

	int KeyDown();
	void Update();

protected:
	Uint8 * keys;
	std::unique_ptr<Uint8> oldKeys;
	int keyCount;
	const Uint8 *state;
};