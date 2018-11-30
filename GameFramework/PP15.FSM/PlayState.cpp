#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include"InputHandler.h"
#include"PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}

	GameState::update();
}
void PlayState::render()
{
	GameState::render();
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;

}
