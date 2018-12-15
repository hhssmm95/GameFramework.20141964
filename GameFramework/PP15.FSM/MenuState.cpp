#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	GameState::update();
}

void MenuState::render()
{
	GameState::render();
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/background.png",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(
		new LoaderParams(100, 100, 400, 100, "playbutton"),
		s_menuToPlay);

	GameObject* button2 = new MenuButton(
		new LoaderParams(100, 300, 400, 100, "exitbutton"),
		s_exitFromMenu);
	GameObject* bg = new SDLGameObject(
		new LoaderParams(0, 0, 640, 480, "background"));
	m_gameObjects.push_back(bg);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	
	std::cout << "entering MenuState\n";
	return true;

}

bool MenuState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("background");
	std::cout << "exiting MenuState\n";
	return true;

}
void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		PlayState::Instance());

}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}
