#include "stdafx.h"
#include "TimeManager.h"
#include <SDL.h>

const float TimeManager::REFRESH_RATE = 1000.0f/60.0f;

TimeManager::TimeManager()
{
	past = SDL_GetTicks();
	now = past;
	mustUpdate = true;
	deltaTime = 0.0f;
}


TimeManager::~TimeManager()
{
}

void TimeManager::initialize()
{
	CreateSingleton();
}

void TimeManager::update()
{
	now = SDL_GetTicks();
	elapsedTime = now - pastFrame;
	deltaTime = (now - past) / 1000.0f;
	if (elapsedTime >= REFRESH_RATE) 
	{ 
		pastFrame = now;
		mustUpdate = true;
	}
	past = now;
}
