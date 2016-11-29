#pragma once
#include "Singleton.h"
class SoundManager :public Singleton<SoundManager>
{
	friend class Singleton<SoundManager>;
private:
	SoundManager();
public:

	virtual ~SoundManager();
	static void initialize();
	void update();
};

