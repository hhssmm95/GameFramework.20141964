#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Game.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"GameOverState.h"
#include"CollisionManager.h"
#include "ProjectileManager.h"
#include<time.h>

const std::string PlayState::s_playID = "PLAY";
CollisionManager* TheCollisionManager::s_pInstance = 0;
ProjectileManager* TheProjectileManager::s_pInstance = 0;
void PlayState::update()
{
	for (int i = 3; i < m_gameObjects.size(); i++)
	{
		if (CollisionManager::Instance()->checkCollision(
			dynamic_cast<SDLGameObject*> (m_gameObjects[2]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(
				new GameOverState());
		}
	}
		
	
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && shotCooltime >= 10)
	{
		TheProjectileManager::Instance()->Shot(m_gameObjects[2]->getPosition().getX() + 50,
			m_gameObjects[2]->getPosition().getY()+40, 10, m_gameObjects[2]->getVelocity().getX());
		shotCooltime = 0;
		
	}

	for (int i = 3; i < m_gameObjects.size(); i++)
	{
		if (TheProjectileManager::Instance()->onHit(m_gameObjects[i]))
		{
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
		score++;
	}
	

	if(spawnCooltime >= 50)
	{
		GameObject* enemys = new Enemy(
			new LoaderParams(650, getRandomSpawnPoint(), 128, 55, "helicopter2"), 5);
		m_gameObjects.push_back(enemys);
		spawnCooltime = 0;
	}
	TheProjectileManager::Instance()->update();
	GameState::update();

	shotCooltime++;
	spawnCooltime++;

}
void PlayState::render()
{
	GameState::render();
	TheProjectileManager::Instance()->render();
	/*TextureManager::Instance()->drawText("score_text", 10, 10,
		TheGame::Instance()->getRenderer());
*/
	TextureManager::Instance()->UpdateAndDrawNumber(score, 100, 10,
		TheGame::Instance()->getRenderer());
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
	if (!TheTextureManager::Instance()->load("assets/background.png",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	/*if (!TheTextureManager::Instance()->loadText("SCORE: ", "score_text", 
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}*/
	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	/*GameObject* enemy = new Enemy(
		new LoaderParams(500, 100, 128, 55, "helicopter2"), 5)*/;
	GameObject* bg1 = new Background(
		new LoaderParams(0, 0, 640, 480, "background"));
	GameObject* bg2 = new Background(
		new LoaderParams(640, 0, 640, 480, "background"));
	m_gameObjects.push_back(bg1);
	m_gameObjects.push_back(bg2);
	m_gameObjects.push_back(player);
	//m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	TheTextureManager::Instance()->clearFromTextureMap("background");

	std::cout << "exiting PlayState\n";
	return true;

}

int PlayState::getRandomSpawnPoint()
{
	srand(time(NULL));
	int y;
	for(int i = 0; i<5; i++)
		y = rand()%301 + 100;
	return y;
}

