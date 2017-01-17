#pragma once
#include "Component.h"
#include <SDL.h>
class Image :
	public Component
{
public:
	SDL_Texture * imageAsset;	
	Image();
	virtual ~Image();
};

