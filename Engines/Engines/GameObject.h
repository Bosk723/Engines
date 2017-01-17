#pragma once
#include <string>

#include "Component.h"
#include "Transform.h"
#include "Image.h"



class GameObject
{
private:

	static const int componentsSize =2;//number of components, depends on the available components to use 
	Component *components[componentsSize];
	Component *getComponent(std::string typeOfComponent);
public:
	
	
	GameObject();
	virtual ~GameObject();
	void update();


	Component *addComponent(std::string typeOfComponent);
	
	void deleteComponent(std::string typeOfComponent);
	Transform *getTransform();
	Image *getImage();
};

