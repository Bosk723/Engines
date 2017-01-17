#include "stdafx.h"
#include <SDL.h>
#include "InputManager.h"


InputManager::InputManager()
{
	gameRunning = true;
}

InputManager::~InputManager()
{
}

void InputManager::initialize()
{
	CreateSingleton();
}

void InputManager::update()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			OnQuit();
			break;
		case SDL_KEYDOWN:
			OnKeyDown(&event);
			break;
		case SDL_KEYUP:
			OnKeyUp(&event);
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
			break;
		}
	}
}

void InputManager::OnQuit()
{
	gameRunning = false;
}

void InputManager::OnKeyDown(SDL_Event* evt)
{
	mKeys[evt->key.keysym.sym] = 1;
}
void InputManager::OnKeyUp(SDL_Event* evt)
{
	mKeys[evt->key.keysym.sym] = 0;
}