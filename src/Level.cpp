#include "Level.h"


const int NUM_OF_LEVELS = 1;

Level::Level() :
    m_level(1),
    m_timer(0),
    m_levelSize(0,0)
{
}

void Level::buildLevel()
{
    std::ifstream board_file;
    board_file.open("C:\\Users\\sajaabu\\source\\repos\\Project\\src\\1.txt"); //m_fileName
    if (!board_file) //if the file didn't succeed in opening
    {
        std::cerr << "Error: File could NOT be opened !!!";
        exit(1);
    }
    std::string time_str;
    getline(board_file, time_str);
    if (time_str == "T")
    {
        getline(board_file, time_str);
        std::stringstream geek(time_str);
        float levelTimer;
        geek >> levelTimer; //the time from string to float
        m_timer = levelTimer;
    }
    else
    {

    }
    calculateLevelSize(board_file);
    std::cout << m_levelSize.x << " " << m_levelSize.y << std::endl;
    startLevel();

}

void Level::startLevel()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Save The King Level " + std::to_string(m_level));
    font1.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    while (window.isOpen())
    {
        window.clear();
        m_clock.getElapsedTime();
        sf::Text m_helpText = sf::Text(sf::String(std::to_string(m_clock.getElapsedTime().asSeconds())), font1);
        m_helpText.setCharacterSize(20);
        float time2 = m_timer - m_clock.getElapsedTime().asSeconds();
        sf::Text m_time = sf::Text(sf::String(std::to_string(time2)), font1);
        m_time.setCharacterSize(20);
        sf::Vector2f pos(17.0f,17.0f);
        m_time.setPosition(pos);
        window.draw(m_helpText);
        window.draw(m_time);
        window.display();
        if (auto event = sf::Event{}; window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: //if the user closes the window then close the window and exit
                window.close();
                break;
            }
        }
    }
}

std::string Level::createFileName()
{
    return ("C:\\" + std::to_string(m_level) + ".txt");
}

void Level::levelOperator()
{
    for (; m_level <= NUM_OF_LEVELS; m_level++)
    {
        m_fileName = createFileName();
        buildLevel(); //why to make file name private? when lose/time is up
    }
}

void Level::calculateLevelSize(std::ifstream& board_file)
{
    while (!board_file.eof())
    {
        std::string line;
        getline(board_file, line);
        m_levelSize.x = ((line.size() > m_levelSize.x) ? unsigned int(line.size()) : m_levelSize.x);
        m_levelSize.y++;
    }
}

void Level::readLevel(std::ifstream& board_file)
{
    std::string line;
    board_file.seekg(0); //erturn to the beginning of the file
    getline(board_file, line);
    getline(board_file, line);
    //start reading the level
    while (!board_file.eof())
    {

    }
}