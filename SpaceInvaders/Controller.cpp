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
	window.loadWindow();
	player.loadShip(window.gameWindow, window.renderer);

	AddNPC();
	loadNPCS();

	running = true;
	GameLoop();
}

void Controller::GameLoop() {

	while (running) {
		Update();
		KeyDown();
		window.draw(player.spaceShipDrawable, player.spaceShipCoords);
		drawNPCS();
		window.renderClear();
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
		//window.spaceShipSpawn.y = window.spaceShipSpawn.y - 1;
	}

	if (state[SDL_SCANCODE_DOWN]) {
		std::cout << "Ned" << std::endl;
		//window.spaceShipSpawn.y = window.spaceShipSpawn.y + 1;
	}

	if (state[SDL_SCANCODE_LEFT]) {
		std::cout << "Venstre" << std::endl;

		if (player.spaceShipCoords.x < 0) {

		}
		else {
			player.spaceShipCoords.x = player.spaceShipCoords.x - 1;
			SDL_Delay(1);
		}
	}

	if (state[SDL_SCANCODE_RIGHT]) {
		std::cout << "H�yre" << std::endl;

		if (player.spaceShipCoords.x > 950) {

		}
		else {
			player.spaceShipCoords.x = player.spaceShipCoords.x + 1;
			SDL_Delay(1);
		}
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

void Controller::AddNPC() {
	NPC npc(400, 700);
	npcs.push_back(npc);
}

void Controller::loadNPCS() {

	std::vector<NPC>::iterator it;
	for (it = npcs.begin(); it != npcs.end(); it++) {
		it->loadNPC(window.gameWindow, window.renderer);
	}
}

void Controller::drawNPCS() {
	std::vector<NPC>::iterator it;
	for (it = npcs.begin(); it != npcs.end(); it++) {
		window.drawNPC(it->NPCDrawable, it->NPCCoords);
	}
}