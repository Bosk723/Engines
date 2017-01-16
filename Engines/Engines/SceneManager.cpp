#include "stdafx.h"
#include "SceneManager.h"
#include <vector>
#include "GameObject.h"
#include <SDL.h>


SceneManager::SceneManager()
{
	background = NULL;
}


SceneManager::~SceneManager()
{
}

void SceneManager::initialize()
{

	CreateSingleton();



}

void SceneManager::update()
{

}

void SceneManager::addObjectToScene(GameObject object)
{
	sceneObjects.insert(sceneObjects.end(), object);
	
}

void SceneManager::addBackground(std::string imagePath)
{
	background= SDL_LoadBMP(imagePath.c_str());
}
