#pragma once
#include "Singleton.h"
#include <SDL.h>
#include <string>
#include "GameObject.h"
class RenderManager : public Singleton<RenderManager>
{
	friend class Singleton<RenderManager>;
private:

	RenderManager();

public:
	 static const int SCREEN_WIDTH ;
	 static const int SCREEN_HEIGHT;
	//PRUEBA DE IMAGEN
	 bool init();
	bool loadMedia(std::string imagePath, Image* image);
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

	virtual ~RenderManager();
	static void initialize();
	void update();

};

