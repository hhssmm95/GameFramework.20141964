#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual Vector2D getPosition();
	virtual Vector2D getVelocity();
	virtual void setVelocity_X(int x);
	virtual void setVelocity_Y(int y);
	int getWidth();
	int getHeight();
protected:
	//int m_x;
	//int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	
	std::string m_textureID;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

};
