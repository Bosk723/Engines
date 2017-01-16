#include "stdafx.h"
#include "RenderManager.h"
#include <SDL.h>
#include <string>
#include "GameObject.h"
#include "SceneManager.h"

//Screen dimension constants
static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 800;
RenderManager::RenderManager()
{
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
	bool quit = false;

			if (SceneManager::GetInstance().background != NULL)
			{
				//Apply the image
				SDL_BlitSurface(SceneManager::GetInstance().background, NULL, gScreenSurface, NULL);
			}

				//Apply the image stretched

			for (int i = 0; i < SceneManager::GetInstance().sceneObjects.size(); i++)
			{
				if (SceneManager::GetInstance().sceneObjects.at(i).getImage() != NULL &&
					SceneManager::GetInstance().sceneObjects.at(i).getImage()->imageAsset != NULL)
				{
					SDL_BlitScaled(SceneManager::GetInstance().sceneObjects.at(i).getImage()->imageAsset,
						NULL, gScreenSurface,
						&SceneManager::GetInstance().sceneObjects.at(i).getTransform()->transform);
				}
				
			}
				


				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
	
}

bool RenderManager::init()
{
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
		//RENDER
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	/*stretchRect.x = SCREEN_WIDTH / 2;
	stretchRect.y = SCREEN_HEIGHT / 2;
	stretchRect.w = SCREEN_WIDTH / 4;
	stretchRect.h = SCREEN_HEIGHT / 4;*/
	return success;
}

bool RenderManager::loadMedia(std::string imagePath,Image* image)
{

	//Loading success flag
	bool success = true;
	//RENDER
	//Load splash image
	image->imageAsset = SDL_LoadBMP(imagePath.c_str());
	if (image->imageAsset == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
		success = false;
	}
	/*gRun = SDL_LoadBMP("Sprites/hello_world.bmp");
	if (gRun == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Sprites/hello_world.bmp", SDL_GetError());
		success = false;
	}
	*/
	return success;
}

void RenderManager::close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;
	SDL_FreeSurface(gRun);
	gRun = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}