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
	player.loadShip(window.gameWindow, window.renderer);
	//bullet.loadBullet(window.gameWindow, window.renderer);
	entityManager->AddNPCS();
	running = true;
	GameLoop();

}

void Controller::GameLoop() {

	while (running) {
		Update();
		KeyDown();
		window.draw(player.spaceShipDrawable, player.spaceShipCoords);
		window.draw(bullet.bulletDrawable, bullet.bulletCoords);
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

		if (player.spaceShipCoords.x < 0) {

		}
		else {
			player.spaceShipCoords.x = player.spaceShipCoords.x - 1;
		}
	}

	if (state[SDL_SCANCODE_RIGHT]) {

		if (player.spaceShipCoords.x > 950) {

		}
		else {
			player.spaceShipCoords.x = player.spaceShipCoords.x + 1;
		}
	}

	if (state[SDL_SCANCODE_SPACE] && !bullet.isAlive) {
		bullet.isAlive = true;
		std::cout << "Space" << std::endl;
		bullet.loadBullet(window.gameWindow, window.renderer, player.spaceShipCoords.x, player.spaceShipCoords.y);
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
