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
	entityManager = new EntityManager(&window);
	player.loadEntity(window.gameWindow, window.renderer, 400, 850);
	entityManager->AddNPCS();
	running = true;
	GameLoop();

}

void Controller::GameLoop() {

	while (running) {
		Update();
		KeyDown();
		window.draw(player.entityDrawable, player.entityCoords);
		window.draw(bullet.entityDrawable, bullet.entityCoords);
		entityManager->drawNPCS();

		bullet.bulletMovement();

		window.renderClear();
		SDL_Delay(1);
	}
}

void Controller::Update() {

	memcpy(oldKeys.get(), keys, keyCount * sizeof(Uint8));
	SDL_PumpEvents();

}

void Controller::KeyDown() {

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_UP]) {
		//window.spaceShipSpawn.y = window.spaceShipSpawn.y - 1;
	}

	if (state[SDL_SCANCODE_DOWN]) {
		//window.spaceShipSpawn.y = window.spaceShipSpawn.y + 1;
	}

	if (state[SDL_SCANCODE_LEFT]) {

		if (player.entityCoords.x < 0) {

		}
		else {
			player.entityCoords.x = player.entityCoords.x - 1;
		}
	}

	if (state[SDL_SCANCODE_RIGHT]) {

		if (player.entityCoords.x > 950) {

		}
		else {
			player.entityCoords.x = player.entityCoords.x + 1;
		}
	}

	if (state[SDL_SCANCODE_SPACE] && !bullet.isAlive) {
		bullet.isAlive = true;
		std::cout << "Space" << std::endl;
		bullet.loadEntity(window.gameWindow, window.renderer, (player.entityCoords.x + 20), (player.entityCoords.y - 10));
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