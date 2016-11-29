#include "stdafx.h"
#include "GameManager.h"
#include "RenderManager.h"

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
}

void GameManager::update()
{
	//RenderManager::update();
}