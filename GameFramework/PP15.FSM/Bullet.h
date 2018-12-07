#pragma once
#include"SDLGameObject.h"
#include <SDL.h>
class Bullet : public SDLGameObject
{
private:
	void handleInput();
public:
	Bullet(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	//virtual SDL_Rect getCollider();
};