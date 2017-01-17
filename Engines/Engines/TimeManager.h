#pragma once
#include "Singleton.h"
class TimeManager :
	public Singleton<TimeManager>
{
	friend class Singleton<TimeManager>;
private:
	TimeManager();
public:

	virtual ~TimeManager();
	static void initialize();
	void update();
};

