#include "stdafx.h"
#include "SceneManager.h"
#include <vector>
#include "GameObject.h"
#include <SDL.h>


SceneManager::SceneManager()
{

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
	for (int i = 0; i < GetInstance().sceneObjects.size(); i++)
	{
		GetInstance().sceneObjects.at(i).update();
	}
}

void SceneManager::addObjectToScene(GameObject object)
{
	sceneObjects.insert(sceneObjects.end(), object);
	
}