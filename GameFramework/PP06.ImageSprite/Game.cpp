#include "Game.h"
#include <iostream>
#include <SDL_image.h>

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


	//SDL_Surface* pTempSurface = IMG_Load("assets/animate.png");
	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	SDL_Surface* bgSurface = IMG_Load("assets/background.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	m_pBGTexture = SDL_CreateTextureFromSurface(m_pRenderer, bgSurface);

	
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle1.w, &m_sourceRectangle1.h);
	SDL_QueryTexture(m_pBGTexture, NULL, NULL, &bgSR.w, &bgSR.h);

	m_sourceRectangle1.w = 128;
	m_sourceRectangle1.h = 82;
	bgSR.w = 480;
	bgSR.h = 480;

	m_sourceRectangle1.x = 0;
	m_sourceRectangle1.y = 0;
	m_destinationRectangle.x = 70;
	m_destinationRectangle.y = 400;
	m_destinationRectangle.w = m_sourceRectangle1.w;
	m_destinationRectangle.h = m_sourceRectangle1.h;

	bgDR.x = bgSR.x = 0;
	bgDR.y = bgSR.y = 0;
	bgDR.w = bgSR.w;
	bgDR.h = bgSR.h;

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	
	SDL_RenderCopy(m_pRenderer, m_pBGTexture, &bgSR, &bgDR);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle1, &m_destinationRectangle);
	
	
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