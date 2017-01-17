#include "stdafx.h"
#include "Transform.h"
#include <SDL.h>

 

Transform::Transform()
{
	rect.x = 0;
	rect.y = 0;
	rect.w = 100;
	rect.h = 100;
	x = 0;
	y = 0;
}

float Transform::getX() { return x; }
float Transform::getY() { return y; }
SDL_Rect Transform::getRect() { return rect; }
void Transform::setX(float newX) { 
	x = newX; 
	rect.x = x;
}
void Transform::setY(float newY)
{
	y = newY;
	rect.y = y;
}
void Transform::setScale(int newW, int newH)
{
	rect.w = newW;
	rect.h = newH;
}

Transform::~Transform()
{
}
