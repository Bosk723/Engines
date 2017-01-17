#include "stdafx.h"
#include "GameManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "SceneManager.h"

GameManager::GameManager()
{
	
}


GameManager::~GameManager()
{
	SoundManager::GetInstance().~SoundManager();
	RenderManager::GetInstance().~RenderManager();
	SceneManager::GetInstance().~SceneManager();
	InputManager::GetInstance().~InputManager();
	TimeManager::GetInstance().~TimeManager();
}

void GameManager::initialize()
{	
	CreateSingleton();
	TimeManager::initialize();
	InputManager::initialize();
	SceneManager::initialize();
	RenderManager::initialize();
	SoundManager::initialize();
}

void GameManager::update()
{
	TimeManager::GetInstance().update();
	InputManager::GetInstance().update();
	SceneManager::GetInstance().update();
	//Fixed update for the render
	if (TimeManager::GetInstance().mustUpdate)
	{
		RenderManager::GetInstance().update();
		TimeManager::GetInstance().mustUpdate = false;
	}
	SoundManager::GetInstance().update();
}

void GameManager::gameLoop()
{
	while (InputManager::GetInstance().gameRunning)
	{
		update();
	}
	GetInstance().~GameManager();
}