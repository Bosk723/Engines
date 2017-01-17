#pragma once
#include "Singleton.h"
#include <string.h>
class SoundManager :public Singleton<SoundManager>
{
	friend class Singleton<SoundManager>;
private:
	SoundManager();
	bool loadSound(std::string sound);
	bool loadMusic(std::string music);
	void freeSound();
	void freeMusic();
public:

	virtual ~SoundManager();
	static void initialize();
	void update();
	void playSound(std::string soundName);
	void playMusic(std::string soundMusic);
	

};
