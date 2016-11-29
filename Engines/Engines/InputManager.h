#pragma once
#include "Singleton.h"
class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
private:
	InputManager();
public:

	virtual ~InputManager();
	static void initialize();
	void update();
};

