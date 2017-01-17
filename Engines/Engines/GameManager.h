#pragma once

#include "Singleton.h"


class GameManager :	public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:
	
	GameManager();

public:
	static void initialize();
	void update();
	void gameLoop();
	virtual ~GameManager();
};

