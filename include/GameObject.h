#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(sf::Texture& image, float x, float y): m_image(image) { m_position.x = x; m_position.y = y; };
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual sf::Sprite& initializeImg() = 0;
	virtual ~GameObject() = default;

protected:
	sf::Sprite m_image;
	sf::Vector2f m_position;
	int m_objectSizeFitter = 45;

};
//we will add sf::sprite as protected member
//and initialize it in the c-tor of GameOject : m_sprite(m_texture)
//and the c-tor recieves texture from unique_ptr