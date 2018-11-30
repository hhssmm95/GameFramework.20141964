#pragma once
#include "Player.h"
#include "GameObject.h"
#include "GameStateMachine.h"
#include <SDL.h>
#include <vector>
class Game
{
private:


	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	GameObject* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;

	Game() {}
	~Game() {}

public:

	SDL_Renderer * getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}


	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void quit();
};


typedef Game TheGame;
