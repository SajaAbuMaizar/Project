#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Help
{
public:
	Help(int width, int hight);
	void showHelp();
	void fillHelpTextVec();
	void fillIconsVec();
	void handleIconsClick(const sf::Vector2f& location);
	void openInfoWindow(const sf::Text info);

private:
	std::vector<sf::Sprite> m_iconsVec;
	std::vector<sf::Text> m_helpText;
	sf::Texture m_kingTex;
	sf::Texture m_mageTex;
	sf::Texture m_warriorTex;
	sf::Texture m_thiefTex;
	sf::Font font;
	int m_width;
	int m_hight;
};