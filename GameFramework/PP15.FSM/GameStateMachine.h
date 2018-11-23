#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
	void render();
	void update();

private:
	GameState * m_currentState;
	GameState* m_prevState;
};
