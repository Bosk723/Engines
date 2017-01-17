// Engines.cpp : Defines the entry point for the console application.

#include <iostream>
#include "stdafx.h"
#include <SDL.h>
#include <stdio.h>
#include "GameManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "SceneManager.h"
#include "RenderManager.h"
#include "SoundManager.h"

int main(int argc, char* args[])
{
	GameManager::initialize();
	GameObject go;
	GameObject go2;
	GameObject go3;
	
	go.addComponent("image");
	go.getTransform()->setX(200);
	go.getTransform()->setY(200);

	SoundManager::GetInstance().playSound("Sounds/scratch.wav");
	SoundManager::GetInstance().playMusic("Sounds/beat.wav");
	
	RenderManager::GetInstance().loadMedia("Sprites/hello_world.bmp", go.getImage());
	SceneManager::GetInstance().addObjectToScene(go);
	SceneManager::GetInstance().addObjectToScene(go2);
	SceneManager::GetInstance().addObjectToScene(go3);

	RenderManager::GetInstance().loadBackground("Sprites/hello_world.bmp");
	GameManager::GetInstance().gameLoop();

	return 0;
}