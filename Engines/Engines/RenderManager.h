#pragma once
#include "Singleton.h"
class RenderManager : public Singleton<RenderManager>
{
	friend class Singleton<RenderManager>;
private:

	RenderManager();

public:
	
	virtual ~RenderManager();
	static void initialize();
	void update();

};

