#pragma once
#include<map>
#include<SDL.h>
class TextureManager
{
private:

	std::map<std::string, SDL_Texture*>m_textureMap;

	TextureManager() {}
	~TextureManager() {}
public:


	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	bool loadText(const char* message, std::string id, SDL_Renderer* pRenderer);
	bool drawText(std::string id, int x, int y, SDL_Renderer* pRenderer);
	bool UpdateAndDrawNumber(int score, int x, int y, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, double angle,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearFromTextureMap(std::string id);
	static TextureManager* Instance()
	{
		static TextureManager* s_pInstance;

		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}



};

typedef TextureManager TheTextureManager;