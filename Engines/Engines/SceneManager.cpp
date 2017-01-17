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
		for (int j = 0; j < GetInstance().sceneObjects.at(i).componentsSize; j++)
		{
			GetInstance().sceneObjects.at(i).components[j]->update();
		}
	}
}

void SceneManager::addObjectToScene(GameObject object)
{
	sceneObjects.insert(sceneObjects.end(), object);
	
}