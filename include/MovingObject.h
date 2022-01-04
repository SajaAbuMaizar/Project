#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(sf::Texture& image, float x, float y) : GameObject(image, x, y), m_firstDraw(true) {};
	//using GameObject::GameObject;
	virtual int move(sf::Time deltaTime, const char* NextStep) = 0;
	virtual sf::Sprite& initializeImg() = 0;
	void setDirection(sf::Keyboard::Key key);
	sf::Vector2f getPosition() const;
	sf::Vector2f getDirection() const;

protected:
	sf::Vector2f m_direction;
	bool m_firstDraw;

};