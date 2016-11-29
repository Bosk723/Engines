#include "stdafx.h"
#include "GameManager.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "AssetsManager.h"

GameManager::GameManager()
{

}


GameManager::~GameManager()
{
}

void GameManager::initialize()
{
	
	CreateSingleton();
	RenderManager::initialize();
	InputManager::initialize();
	TimeManager::initialize();
	SoundManager::initialize();
	SceneManager::initialize();
	AssetsManager::initialize();
}

void GameManager::update()
{
	RenderManager::GetInstance().update();
	InputManager::GetInstance().update();
	TimeManager::GetInstance().update();
	SoundManager::GetInstance().update();
	SceneManager::GetInstance().update();
	AssetsManager::GetInstance().update();
}