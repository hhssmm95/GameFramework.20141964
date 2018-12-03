#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	int m_numFrames;
public:
	Enemy(const LoaderParams* pParams, int numsFrames);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();
};
