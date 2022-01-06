#include "LevelData.h"

LevelData::LevelData(int level, sf::Vector2u levelSize) : m_levelNum(level),
                                                          m_levelSize(levelSize),
	                                                      m_player(0),
	                                                      m_thiefHasKey(false)
{
	m_font.loadFromFile("C:/Windows/Fonts/CASTELAR.ttf");
}

void LevelData::initializeData(int player, bool key)
{
	m_player = player;
	m_thiefHasKey = key;
}


void LevelData::draw(sf::RenderWindow& window)
{
	updateLevelData();
	setDataDesign();
	for (int index = 0; index < m_data.size(); index++)
		window.draw(m_data[index]);
	m_data.clear();
}

void LevelData::updateLevelData()
{
	NameOfCharacter(); // update the name of the current character
	m_keyData = ((m_thiefHasKey) ? "Yes" : "No");
	m_data.push_back(sf::Text("Level : ", m_font));
	m_data.push_back(sf::Text("Character Playing  : ", m_font));
	m_data.push_back(sf::Text("The Time Now : ", m_font));
	m_data.push_back(sf::Text("Time Left : ", m_font));
	m_data.push_back(sf::Text("Does The Thief Has Key? ", m_font));
}

void LevelData::setDataDesign()
{
	for (int index = 0; index < m_data.size(); index++)
	{
		sf::Vector2f linePos(0.0f, (m_levelSize.y * 45) + (index + 1)*20);
		m_data[index].setPosition(linePos);
		m_data[index].setCharacterSize(20);
		m_data[index].setOutlineColor(sf::Color::Black);
		m_data[index].setOutlineThickness(1.f);
	}
}

void LevelData::NameOfCharacter()
{
	switch (m_player)
	{
	case 0:
		m_currCharacter = "King";
		break;
	case 1:
		m_currCharacter = "Mage";
		break;
	case 2:
		m_currCharacter = "Warrior";
		break;
	case 3:
		m_currCharacter = "Thief";
		break;
	}
}