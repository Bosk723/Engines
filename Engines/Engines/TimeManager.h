#pragma once
#include "Singleton.h"
class TimeManager :
	public Singleton<TimeManager>
{
	friend class Singleton<TimeManager>;
private:
	TimeManager();
public:
	int now;
	int past;
	int pastFrame;
	int elapsedTime;
	float deltaTime;
	
	bool mustUpdate;
	static const float REFRESH_RATE;
	virtual ~TimeManager();
	static void initialize();
	void update();
};

