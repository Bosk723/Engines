#include "stdafx.h"
#include "RenderManager.h"
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


//PRUEBA DE IMAGEN
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gRun = NULL;

SDL_Rect stretchRect;

RenderManager::RenderManager()
{

}


RenderManager::~RenderManager()
{
	close();
}

void RenderManager::initialize()
{

	CreateSingleton();
	
	init();
	loadMedia();
	
}

void RenderManager::update()
{
	bool quit = false;

	//Start up SDL and create window
	/*if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{*/
		//Load media
		/*if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{*/
			

				//Apply the image
				SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

				//Apply the image stretched


				SDL_BlitScaled(gRun, NULL, gScreenSurface, &stretchRect);


				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			

		//}
	//}

	//Free resources and close SDL
	
}

bool init()
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
	stretchRect.x = SCREEN_WIDTH / 2;
	stretchRect.y = SCREEN_HEIGHT / 2;
	stretchRect.w = SCREEN_WIDTH / 4;
	stretchRect.h = SCREEN_HEIGHT / 4;
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	//RENDER
	//Load splash image
	gHelloWorld = SDL_LoadBMP("Sprites/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Sprites/hello_world.bmp", SDL_GetError());
		success = false;
	}
	gRun = SDL_LoadBMP("Sprites/hello_world.bmp");
	if (gRun == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Sprites/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
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