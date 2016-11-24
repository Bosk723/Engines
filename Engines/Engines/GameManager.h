#pragma once

#include "Singleton.h"


class GameManager :	public Singleton<GameManager>
{
	friend class Singleton<GameManager>;

private:
	
	GameManager();

public:
	
	
	virtual ~GameManager();
	static void initialize();
	void update();

};

