#pragma once
#include "Singleton.h"
class AssetsManager :
	public Singleton<AssetsManager>
{
	friend class Singleton<AssetsManager>;
private:
	AssetsManager();
public:

	virtual ~AssetsManager();
	static void initialize();
	void update();
};

