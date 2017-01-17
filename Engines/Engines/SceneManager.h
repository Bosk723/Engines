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
	void addObjectToScene(GameObject object);
	static void initialize();
	void update();
	virtual ~SceneManager();
};
