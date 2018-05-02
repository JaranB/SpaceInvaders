#include "stdafx.h"
#include "InputManager.h"
#include <iostream>


InputManager::InputManager() {

	InputManager::oldKeys = std::unique_ptr<Uint8>(new Uint8[keyCount]);
	state = SDL_GetKeyboardState(NULL);

}


InputManager::~InputManager() {}

void InputManager::Update() {
	memcpy(oldKeys.get(), keys, keyCount * sizeof(Uint8));
	SDL_PumpEvents();
}

int InputManager::KeyDown() {

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_UP]) {
		return 1;
	}

	if (state[SDL_SCANCODE_DOWN]) {
		return 2;
	}

	if (state[SDL_SCANCODE_LEFT]) {
		return 3;
	}

	if (state[SDL_SCANCODE_RIGHT]) {
		return 4;
	}

	if (state[SDL_SCANCODE_ESCAPE]) {
		exit(0);
	}

	return 0;
}