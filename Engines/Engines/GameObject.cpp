#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"
#include <string>
#include "Transform.h"
#include "Image.h"


 


GameObject::GameObject()
{
	components[0] = NULL;
	components[1] = NULL;
}


GameObject::~GameObject()
{
}

void GameObject::update()
{

}

Component *GameObject::addComponent(std::string typeOfComponent)
{
	if (typeOfComponent.compare("transform")==0)
	{
		if (components[0] == NULL )
		{
			components[0] = new Transform();
			//int  AAAAAAAAA = dynamic_cast<Transform*>( components[0])->x;
			
		}
	}
	else if(typeOfComponent.compare("image") == 0)
	{
		if (components[0] == NULL)
		{
			components[0] = new Transform();
		}
		if (components[1] == NULL)
		{
			components[1] =new Image();
		}
	}
	
	return getComponent(typeOfComponent);
}
Component *GameObject::getComponent(std::string typeOfComponent)
{
	if (typeOfComponent.compare("transform") == 0)
	{
		return components[0];
	}
	else if (typeOfComponent.compare("image") == 0)
	{
		return components[1];
	}
	
	return NULL;
	
}

Transform *GameObject::getTransform()
{
	return dynamic_cast<Transform*>(getComponent("transform"));
}
Image *GameObject::getImage()
{
	return dynamic_cast<Image*>(getComponent("image"));
}



void GameObject::deleteComponent(std::string typeOfComponent)
{
	if (typeOfComponent.compare("transform") == 0)
	{
		components[0]=NULL;
	}
	else if (typeOfComponent.compare("image") == 0)
	{
		components[1]=NULL;
	}
}