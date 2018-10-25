#pragma once
#include<SDL.h>
class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL_Texture* m_pTexture;
	//SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle;
	bool m_bRunning;
	int m_currentFrame;
	//TextureManager m_textureManager;
	//TheTextureManager m_textureManager;
	GameObject m_go;
	Player m_player;
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