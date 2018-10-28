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


	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	m_pTexture1 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	m_pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	SDL_Surface* bgTempSurface = IMG_Load("assets/background.png");
	bgTexture = SDL_CreateTextureFromSurface(m_pRenderer, bgTempSurface);

	SDL_FreeSurface(pTempSurface);
	SDL_FreeSurface(bgTempSurface);

	SDL_QueryTexture(m_pTexture1, NULL, NULL, &m_sourceRectangle1.w, &m_sourceRectangle1.h);
	SDL_QueryTexture(m_pTexture2, NULL, NULL, &m_sourceRectangle2.w, &m_sourceRectangle2.h);
	SDL_QueryTexture(bgTexture, NULL, NULL, &bgSrcRect.w, &bgSrcRect.h);

	m_sourceRectangle1.w = 128;
	m_sourceRectangle1.h = 82;
	m_sourceRectangle2.w = m_sourceRectangle1.w;
	m_sourceRectangle2.h = m_sourceRectangle1.h;

	m_sourceRectangle1.x = 0;
	m_sourceRectangle1.y = 0;

	m_destinationRectangle1.x = 50;
	m_destinationRectangle1.y = 400;
	m_destinationRectangle1.w = m_sourceRectangle1.w;
	m_destinationRectangle1.h = m_sourceRectangle1.h;

	m_destinationRectangle2.x = 80;
	m_destinationRectangle2.y = 80;
	
	m_destinationRectangle2.w = m_sourceRectangle2.w;
	m_destinationRectangle2.h = m_sourceRectangle2.h;

	bgDestRect.w = bgSrcRect.w = 480;
	bgDestRect.h = bgSrcRect.h = 480;
	
	bgDestRect.x = bgSrcRect.x = 0;
	bgDestRect.y = bgSrcRect.y = 0;


	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pTexture1, &m_sourceRectangle1, &m_destinationRectangle1);
	SDL_RenderCopy(m_pRenderer, bgTexture, &bgSrcRect, &bgDestRect);
	SDL_RenderCopy(m_pRenderer, m_pTexture2, &m_sourceRectangle2, &m_destinationRectangle2);
	
	
	

	SDL_RenderPresent(m_pRenderer);

}

void Game::update()
{
	m_sourceRectangle1.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	m_sourceRectangle2.x = 128 * int(((SDL_GetTicks() / 200) % 6));

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