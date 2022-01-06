#include "LevelData.h"

LevelData::LevelData(int level, sf::Vector2u levelSize) : m_levelNum(level),
                                                          m_levelSize(levelSize),
	                                                      m_player(0),
	                                                      m_thiefHasKey(false),
	                                                      m_timeLeft(0),
	                                                      m_timeLimitedLevel(false)
{
	m_font.loadFromFile("C:/Windows/Fonts/broadw.ttf");
}

void LevelData::initializeData(int player, bool key, int timeLeft, bool timeLimitedLevel)
{
	m_player = player;
	m_thiefHasKey = key;
	m_timeLeft = timeLeft;
	m_timeLimitedLevel = timeLimitedLevel;
}


void LevelData::draw(sf::RenderWindow& window, sf::Clock clock)
{
	updateLevelData(clock);
	setDataDesign();
	for (int index = 0; index < m_data.size(); index++)
		window.draw(m_data[index]);
	m_data.clear();
}

void LevelData::updateLevelData(sf::Clock clock)
{

	NameOfCharacter(); // update the name of the current character
	m_keyData = ((m_thiefHasKey) ? "Yes" : "No");
	std::string levelString = "Level: " + std::to_string(m_levelNum);
	m_data.push_back(sf::Text(levelString, m_font));

	std::string playerString = "Currently Playing: " + m_currCharacter;
	m_data.push_back(sf::Text(playerString, m_font));

	std::string keyString = "Does The Thief Has Key? " + m_keyData;
	m_data.push_back(sf::Text(keyString, m_font));

	std::string clockString = "Time passed: " + std::to_string(int(clock.getElapsedTime().asSeconds()));
	m_data.push_back(sf::Text(clockString, m_font));

	if (m_timeLimitedLevel)
	{
		std::string timerString = "Time Left: " + std::to_string(m_timeLeft);
		m_data.push_back(sf::Text(timerString, m_font));
	}
}

void LevelData::setDataDesign()
{
	for (int index = 0; index < m_data.size(); index++)
	{
		sf::Vector2f linePos(0.0f, (m_levelSize.y * 45) + (index + 1)*20);
		m_data[index].setPosition(linePos);
		m_data[index].setCharacterSize(20);
		//m_data[index].setColor(sf::Color::Transparent);
		//m_data[index].setOutlineColor(sf::Color::White);
		//m_data[index].setOutlineThickness(1.f);
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