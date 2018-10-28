#pragma once
#include<SDL.h>

class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture1;
	SDL_Texture* m_pTexture2;
	SDL_Texture* bgTexture;
	SDL_Rect m_sourceRectangle1;
	SDL_Rect m_sourceRectangle2;
	SDL_Rect bgSrcRect;
	SDL_Rect m_destinationRectangle1;
	SDL_Rect m_destinationRectangle2;
	SDL_Rect bgDestRect;
	bool m_bRunning;

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }


};
