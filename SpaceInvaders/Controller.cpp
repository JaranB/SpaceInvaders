#include "stdafx.h"
#include "Controller.h"
#include "Window.h"
#include "InputManager.h"
#include <iostream>



Controller::Controller()
{ }


Controller::~Controller()
{ }

void Controller::run() {
	Window window;
	window.loadWindow();

	InputManager inp;

	while (true) {

		inp.Update();
		int keyDown = inp.KeyDown();

		if (keyDown == 1) {
			std::cout << "Opp" << std::endl;
		}

		if (keyDown == 2) {
			std::cout << "Ned" << std::endl;
		}

		if (keyDown == 3) {
			std::cout << "Venstre" << std::endl;
		}

		if (keyDown == 4) {
			std::cout << "Høyre" << std::endl;
		}
	}
}
