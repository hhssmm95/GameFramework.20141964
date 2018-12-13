#include "ProjectileManager.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
#include"Vector2D.h"
#include"CollisionManager.h"
#include <SDL.h>


ProjectileManager::ProjectileManager()
{
	if (!TheTextureManager::Instance()->load("assets/bullet1.png",
		"bullet1", TheGame::Instance()->getRenderer())) {
		std::cout<<"bullet1 load failure"<<std::endl;
	}
	if (!TheTextureManager::Instance()->load("assets/bullet2.png",
		"bullet2", TheGame::Instance()->getRenderer())) {
		std::cout << "bullet2 load failure" <<std::endl;
	}

}

void ProjectileManager::Shot(int x, int y, Vector2D velocity)
{
	GameObject* bullet = new SDLGameObject(new LoaderParams(x, y, 8, 8, "bullet1"));
	bullets.push_back(bullet);
}

void ProjectileManager::render()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw();
	}
}

void ProjectileManager::onHitEnemy(SDLGameObject* obj)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (TheCollisionManager::Instance()->checkCollision(dynamic_cast<SDLGameObject*>(obj), dynamic_cast<SDLGameObject*>(bullets[i])))
		{

		}
	}
}