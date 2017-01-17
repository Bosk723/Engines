#pragma once
#include "Singleton.h"
#include <map> 
#include <SDL.h>
class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
private:
	InputManager();
	void OnKeyDown(SDL_Event* evt);
	void OnKeyUp(SDL_Event* evt);
	void OnQuit();
public:
	bool gameRunning;
	std::map<int, int>  mKeys;
	virtual ~InputManager();
	static void initialize();
	void update();
};

