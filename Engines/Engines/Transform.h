#pragma once
#include "Component.h"
#include <SDL.h>
class Transform :
	public Component
{
private:
	float x;
	float y;
	SDL_Rect rect;
public:
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void setScale(int x, int y);
	SDL_Rect getRect();
	Transform();
	virtual ~Transform();
};

