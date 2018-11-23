#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
	i != m_gameObjects.size(); i++)
	{
	m_gameObjects[i]->update();
	}
}
void PlayState::render()
{
	for (std::vector<GameObject*>::size_type i = 0;
	i != m_gameObjects.size(); i++)
	{
	m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", TheGame::Instance()->getRenderer()))
	{

		std::cout << "TMload error";

		return false;
	}
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}
