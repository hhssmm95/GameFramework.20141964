#pragma once
#include"SDLGameObject.h"
#include <SDL.h>
#include<vector>
class ProjectileManager
{
private:
	void handleInput();
	std::vector<GameObject*> bullets;
	ProjectileManager();
	~ProjectileManager();
	static ProjectileManager* s_pInstance;
public:
	static ProjectileManager* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new ProjectileManager();
		}
		return s_pInstance;
	}
	void drawBullet();
	void checkCollision();
	void update();
	void clean();
	//virtual SDL_Rect getCollider();
};
typedef ProjectileManager TheProjectileManager;