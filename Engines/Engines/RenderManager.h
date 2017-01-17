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
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	SDL_Window* gWindow = NULL;
	SDL_Rect backgroundTransform;
	SDL_Texture * background;
	SDL_Renderer * mRenderer;

	bool init();
	bool loadMedia(std::string imagePath, Image* image);
	bool loadBackground(std::string imagePath);
	void close();
	virtual ~RenderManager();
	static void initialize();
	void update();

};

