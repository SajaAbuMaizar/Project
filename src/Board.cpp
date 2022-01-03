#include <typeinfo>
#include <iostream>
#include "Board.h"

Board::Board() : m_player(0), m_timer(0)
{
    m_textures.resize(10); //6 = number of characters
    m_textures[0].loadFromFile("Fire.png");
    m_textures[1].loadFromFile("Gate.png");
    m_textures[2].loadFromFile("KingChair.png");
    m_textures[3].loadFromFile("wall.jpg");
    m_textures[4].loadFromFile("TeleportCell.png");
    m_textures[5].loadFromFile("Orc.png");
    m_textures[6].loadFromFile("King.png");
    m_textures[7].loadFromFile("Mage.png");
    m_textures[8].loadFromFile("Warrior.png");
    m_textures[9].loadFromFile("Thief.png");
}

//this function reads the level board from the file
void Board::readLevel(sf::Vector2u levelSize, int timer, sf::Clock clock, std::ifstream& board_file)
{
    m_levelSize = levelSize;
    m_timer = timer;
    m_clock = clock;
    char c;
    std::string line;

    //go back to the beginning of the file
    board_file.seekg(0);

    //ignor two lines (the sketch of the board starts from the 3rd line)
    getline(board_file, line);
    getline(board_file, line);

    //start reading the level
    for (size_t j = 0; j < m_levelSize.y; j++)
    {
        for (size_t i = 0; i < m_levelSize.x + 1; i++)
        {
            c = char(board_file.get());
            if (c == 10 || c == -1) // 10 =\n , -1 = eof
                break;
            readChar(c, i, j);
        }
    }
}

//this function reads every character in the board file and creates
//the object that indicates the characte
void Board::readChar(const char c, const size_t i, size_t& j)
{
    m_board.resize(m_levelSize.y);
    for (unsigned int index = 0; index < m_levelSize.y; index++)
        m_board[index].resize(m_levelSize.x);

    m_characters.resize(4);

    if (c != '\n') //ignore the break
    {
        switch (c)
        {
        case '=':
            m_board[j][i] = std::make_unique<Wall>(m_textures[3], float(i), float(j));
            break;
        case '*':
            m_board[j][i] = std::make_unique<Fire>(m_textures[0], float(i), float(j));
            break;
        case '!':
            m_board[j][i] = std::make_unique<Orc>(m_textures[5], float(i), float(j));
            break;
        case '#':
            m_board[j][i] = std::make_unique<Gate>(m_textures[1], float(i), float(j));
            break;
        case 'X':
            m_board[j][i] = std::make_unique<TeleportCell>(m_textures[4], float(i), float(j));
            break;
        case '@':
            m_board[j][i] = std::make_unique<KingChair>(m_textures[2], float(i), float(j));
            break;
        case 'K':
            m_characters[0] = std::make_unique<King>(m_textures[6], float(i), float(j)); // 0 = king
            break;
        case 'M':
            m_characters[1] = std::make_unique<Mage>(m_textures[7], float(i), float(j));
            break;
        case 'W':
            m_characters[2] = std::make_unique<Warrior>(m_textures[8], float(i), float(j));
            break;
        case 'T':
            m_characters[3] =  std::make_unique<Thief>(m_textures[9], float(i), float(j));
            break;
        default:
            break;
        }
    }
}

//this function starts the level, creates the window and prints the level on it
void Board::startLevel()
{
    sf::RenderWindow window(sf::VideoMode(m_levelSize.x*45, m_levelSize.y*45 + 100), "Save The King Level ");//do the enum / 45 = wall height/width / 100 = for the info
    font1.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    while (window.isOpen())
    {
        window.clear();
        for (size_t j = 0; j < m_levelSize.y; j++)
        {
            for (size_t i = 0; i < m_levelSize.x; i++)
            {
                //ignore nullptr elements and print other elements to the window
                if (m_board[j][i] != nullptr)
                {
                    m_board[j][i]->draw(window);
                }
            }
        }        
        for (int index = 0; index < m_characters.size(); index++)
        {
            m_characters[index]->draw(window);
        }
        /*
        m_clock.getElapsedTime();
        sf::Text m_helpText = sf::Text(sf::String(std::to_string(m_clock.getElapsedTime().asSeconds())), font1);
        m_helpText.setCharacterSize(20);
        int time2 = int(m_timer - m_clock.getElapsedTime().asSeconds());
        sf::Text m_time = sf::Text(sf::String(std::to_string(time2)), font1);
        m_time.setCharacterSize(20);
        sf::Vector2f pos(17.0f,(m_levelSize.y +1) * 45); // 45 = hight of icon, change this later
        m_time.setPosition(pos);
        //window.draw(m_helpText);
        window.draw(m_time);
        */
        window.display();
        if (auto event = sf::Event{}; window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: //if the user closes the window then close the window and exit
                window.close();
                break;
            case sf::Event::KeyPressed:
                handleKeyPressed(event.key.code);

                break;
            }
        }
    }
}

void Board::handleKeyPressed(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Key::P:
        m_player = (m_player == 3) ? 0 : m_player+1;
        break;
    case sf::Keyboard::Key::Up: case sf::Keyboard::Key::Down:
    case sf::Keyboard::Key::Right: case sf::Keyboard::Key::Left:
        const auto deltaTime = m_moveClock.restart();
        m_characters[m_player]->setDirection(key);
        sf::Vector2f pos(m_characters[m_player]->getPosition().x / 45, m_characters[m_player]->getPosition().y / 45);
        sf::Vector2f dir(m_characters[m_player]->getDirection().x * 0.5 , m_characters[m_player]->getDirection().y * 0.5);
        sf::Vector2f temp = pos + dir;
        if (round(temp.x) >= m_levelSize.x || round(temp.y) >= m_levelSize.y || round(temp.x) < 0 || round(temp.y) < 0)
            return;
        const char* NextStep = getNextStep(deltaTime, temp);
        m_characters[m_player]->move(deltaTime, NextStep);
        break;
    }
}

const char* Board::getNextStep(sf::Time deltaTime, sf::Vector2f temp)
{
    const char* NextStep = " ";
        if (m_board[round(temp.y)][round(temp.x)] != nullptr)
            NextStep = typeid(*m_board[round(temp.y)][round(temp.x)]).name();
        return NextStep;
}