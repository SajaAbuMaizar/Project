#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Help
{
public:
	Help(int width, int hight);
	void showHelp();
	void handleIconsClick(const sf::Vector2f& location);
	void showInfo(const sf::Text info);

private:
	std::vector<sf::Sprite> m_iconsVec;
	std::vector<sf::Text> m_helpText;
	sf::Texture m_kingTex;
	sf::Texture m_mageTex;
	sf::Texture m_warriorTex;
	sf::Texture m_thiefTex;
	sf::Texture m_background;
	sf::Font m_font;
	int m_width;
	int m_hight;

	// helper functions:
	void fillHelpTextVec();
	void fillIconsVec();
};