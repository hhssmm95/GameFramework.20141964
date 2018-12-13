#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"GameOverState.h"
#include"CollisionManager.h"
#include "Bullet.h"

const std::string PlayState::s_playID = "PLAY";
CollisionManager* TheCollisionManager::s_pInstance = 0;
void PlayState::update()
{

	if (CollisionManager::Instance()->checkCollision(
		dynamic_cast<SDLGameObject*> (m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new GameOverState());
	}

	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		bullets.push_back(new Bullet(new LoaderParams(m_gameObjects[0]->getPosition().getX(),
			m_gameObjects[0]->getPosition().getY(), 64, 64, "bullet")));
	}

	GameState::update();

	

}
void PlayState::render()
{
	GameState::render();
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(
		new LoaderParams(500, 100, 128, 55, "helicopter2"), 5);
	
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	std::cout << "exiting PlayState\n";
	return true;

}

