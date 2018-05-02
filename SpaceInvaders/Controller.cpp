#include "stdafx.h"
#include "Controller.h"
#include "Window.h"
#include "InputManager.h"
#include <iostream>

Controller::Controller()
{
	Controller::oldKeys = std::unique_ptr<Uint8>(new Uint8[keyCount]);
	state = SDL_GetKeyboardState(NULL);
}


Controller::~Controller()
{ }

void Controller::StartGame() {
	Window window;
	window.loadWindow();
	running = true;
	GameLoop();
}

void Controller::GameLoop() {

	while (running) {
		Update();
		KeyDown();
	}
}

void Controller::Update() {
	memcpy(oldKeys.get(), keys, keyCount * sizeof(Uint8));
	SDL_PumpEvents();
}

void Controller::KeyDown() {

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_UP]) {
		std::cout << "Opp" << std::endl;
	}

	if (state[SDL_SCANCODE_DOWN]) {
		std::cout << "Ned" << std::endl;
	}

	if (state[SDL_SCANCODE_LEFT]) {
		std::cout << "Venstre" << std::endl;
	}

	if (state[SDL_SCANCODE_RIGHT]) {
		std::cout << "Høyre" << std::endl;
	}

	if (state[SDL_SCANCODE_SPACE]) {
		std::cout << "Space" << std::endl;
	}

	if (state[SDL_SCANCODE_P]) {
		std::cout << "Pause" << std::endl;
	}

	if (state[SDL_SCANCODE_M]) {
		std::cout << "Mute" << std::endl; 
	}

	if (state[SDL_SCANCODE_ESCAPE]) {
		exit(0);
	}

}