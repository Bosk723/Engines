#pragma once
#include "Component.h"
#include <SDL.h>
class Transform :
	public Component
{
public:
	SDL_Rect transform;
	float xScale;
	float yScale;
	Transform();
	virtual ~Transform();
};

