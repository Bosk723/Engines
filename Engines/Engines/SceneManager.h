#pragma once
#include "Singleton.h"
class SceneManager :
	public Singleton <SceneManager>
{
	friend class Singleton<SceneManager>;
private:
	SceneManager();
public:

	virtual ~SceneManager();
	static void initialize();
	void update();
};
