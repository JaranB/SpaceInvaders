#pragma once
#include "Window.h"

class EntityManager
{
public:
	EntityManager(Window *gameWindow);
	~EntityManager();

protected:
	Window *m_gameWindow;
};

