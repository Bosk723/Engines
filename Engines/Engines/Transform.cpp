#include "stdafx.h"
#include "Transform.h"
#include <SDL.h>

 

Transform::Transform()
{
	transform.x = 0;
	transform.y = 0;
	transform.w = 100;
	transform.h = 100;
	xScale = 1;
	yScale = 1;
}


Transform::~Transform()
{
}
