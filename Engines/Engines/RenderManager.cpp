#include "stdafx.h"
#include "RenderManager.h"
#include <SDL.h>
#include <string>
#include "GameObject.h"
#include "SceneManager.h"

const int RenderManager::SCREEN_HEIGHT = 800;
const int RenderManager::SCREEN_WIDTH = 800;
//Screen dimension constants
RenderManager::RenderManager()
{
	mRenderer = NULL;
	background = NULL;
	init();
}


RenderManager::~RenderManager()
{
	close();
}

void RenderManager::initialize()
{

	CreateSingleton();
	
}

void RenderManager::update()
{
	//Clean the render
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(mRenderer);

	//Render background
	if (background != NULL)
	{
		SDL_RenderCopy(mRenderer, background, NULL, &backgroundTransform);
	}
	
	//Render GameObjects
	for (int i = 0; i < SceneManager::GetInstance().sceneObjects.size(); i++)
	{

		if (SceneManager::GetInstance().sceneObjects.at(i).getImage() != NULL &&
			SceneManager::GetInstance().sceneObjects.at(i).getImage()->imageAsset != NULL)
		{
			SDL_RenderCopy(mRenderer, SceneManager::GetInstance().sceneObjects.at(i).getImage()->imageAsset, 
							NULL, &SceneManager::GetInstance().sceneObjects.at(i).getTransform()->getRect());
		}
				
	}
				
	SDL_RenderPresent(mRenderer);
}

bool RenderManager::init()
{
	int flags = SDL_WINDOW_SHOWN;

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, flags, &gWindow, &mRenderer)) {
			success = false;
		}

	}
	return success;
}

bool RenderManager::loadMedia(std::string imagePath,Image* image)
{
	bool success = true;

	//Load splash image into texture
	SDL_Surface * surface = SDL_LoadBMP(imagePath.c_str());
	image->imageAsset = SDL_CreateTextureFromSurface(mRenderer, surface);

	if (image->imageAsset == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
		success = false;
	}
	return success;
}

bool RenderManager::loadBackground(std::string imagePath)
{
	bool success = true;

	//Load splash image into texture
	SDL_Surface * surface = SDL_LoadBMP(imagePath.c_str());
	background = SDL_CreateTextureFromSurface(mRenderer, surface);
	if (background == NULL)
	{
		printf("Unable to load background %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
		success = false;
	}
	else
	{
		backgroundTransform.x = 0;
		backgroundTransform.y = 0;
		backgroundTransform.w = SCREEN_WIDTH;
		backgroundTransform.h = SCREEN_HEIGHT;
	}
	return success;
}

void RenderManager::close()
{
	//Destroy renderer
	if (NULL != mRenderer) {
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
	}

	//Destroy background
	if (NULL != background) {
		background = NULL;
	}

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}