#pragma once
#include "Component.h"
class Transform :
	public Component
{
public:
	float x;
	float y;
	float xScale;
	float yScale;
	Transform();
	virtual ~Transform();
};

