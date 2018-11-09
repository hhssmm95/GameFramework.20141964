#pragma once
#include "SDL.h"


class InputHandler
{
	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};


public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D*getMousePosition();


private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
	Vector2D* m_mousePosition;
	std::vector<bool> m_mouseButtonStates;
};


typedef InputHandler TheInputHandler;
