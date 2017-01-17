// Engines.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include <SDL.h>
#include <stdio.h>
#include "GameManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "SceneManager.h"
#include "RenderManager.h"





int main(int argc, char* args[])
{
	
	GameManager::initialize();
	GameObject go;
	GameObject go2;
	GameObject go3;
	
	
	go.addComponent("image");
	go.getTransform()->transform.x = 200;
	go.getTransform()->transform.y = 200;
	
	RenderManager::GetInstance().loadMedia("Sprites/hello_world.bmp", go.getImage());
	SceneManager::GetInstance().addObjectToScene(go);
	SceneManager::GetInstance().addObjectToScene(go2);
	SceneManager::GetInstance().addObjectToScene(go3);

	SceneManager::GetInstance().addBackground("Sprites/hello_world.bmp");

	//INPUT
	SDL_Event e;
	bool quit = false;

		
			while (!quit)
			{
				GameManager::GetInstance().update();
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					//User presses a key
					else if (e.type == SDL_KEYDOWN)
					{
						//Select surfaces based on key press
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							//stretchRect.y -= 5;
							break;

						case SDLK_DOWN:
							//stretchRect.y += 5;
							quit = true;
							break;

						case SDLK_LEFT:
							//stretchRect.x -= 5;
							break;

						case SDLK_RIGHT:
							//stretchRect.x += 5;
							break;

						default:

							break;
						}
					}
				}
			}
			
			GameManager::GetInstance().~GameManager();
	

	//Free resources and close SDL
	




	/*
	//std::cout << "asdf";
	//The window we'll be rendering to
	SDL_Window* window = NULL;;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait 1 second
			SDL_Delay(10000);
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();*/

	return 0;
}






