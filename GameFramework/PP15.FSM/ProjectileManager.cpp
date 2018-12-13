#include "ProjectileManager.h"
#include"InputHandler.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
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

void ProjectileManager::drawBullet()
{
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, TheGame::Instance()->getRenderer());
}
void Bullet::update()
{
	m_velocity.setY(0);
	SDLGameObject::update();


}
void Bullet::clean()
{
	delete(this);
}

void Bullet::handleInput()
{
	
}
