#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;
	}

	else {
		return false;
	}

	
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
	SDL_Surface
	m_pTexture1 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	m_pTexture2 = SDL
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture1, NULL, NULL, &m_sourceRectangle1.w, &m_sourceRectangle1.h);

	m_sourceRectangle1.w = 128;
	m_sourceRectangle1.h = 82;


	m_destinationRectangle1.x = m_sourceRectangle1.x = 0;
	m_destinationRectangle1.y = m_sourceRectangle1.y = 0;
	m_destinationRectangle1.w = m_sourceRectangle1.w;
	m_destinationRectangle1.h = m_sourceRectangle1.h;
	
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture1, &m_sourceRectangle1, &m_destinationRectangle1);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_sourceRectangle1.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean()
{

	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}