#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

class Help
{
public:
	Help(int width, int hight);
	void showHelp();
	void handleIconsClick(const sf::Vector2f& location);
	void showInfo(const std::string info);

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
	std::vector <sf::Text> fillTextVec(const std::string fileName);
	void fillIconsVec();
};