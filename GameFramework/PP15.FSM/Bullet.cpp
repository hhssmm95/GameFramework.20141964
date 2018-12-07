#include "Bullet.h"
#include"InputHandler.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
#include <SDL.h>
Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	this->m_velocity.setX(10);
}
void Bullet::draw()
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
