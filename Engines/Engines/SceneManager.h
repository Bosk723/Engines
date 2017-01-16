#pragma once
#include "Singleton.h"
#include <vector>
#include "GameObject.h"
#include <SDL.h>
class SceneManager :
	public Singleton <SceneManager>
{
	friend class Singleton<SceneManager>;
private:
	SceneManager();
public:
	std::vector<GameObject> sceneObjects;
	SDL_Surface* background;
	void addObjectToScene(GameObject object);
	void addBackground(std::string imagePath);
	virtual ~SceneManager();
	static void initialize();
	void update();
};
