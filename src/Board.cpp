#include <typeinfo>
#include <iostream>
#include "Board.h"

Board::Board()
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
            m_board[j][i] = std::make_unique<KingChair>(m_textures[6], float(i), float(j));
            break;
        case 'M':
            m_board[j][i] = std::make_unique<KingChair>(m_textures[7], float(i), float(j));
            break;
        case 'W':
            m_board[j][i] = std::make_unique<KingChair>(m_textures[8], float(i), float(j));
            break;
        case 'T':
            m_board[j][i] = std::make_unique<KingChair>(m_textures[9], float(i), float(j));
            break;
        default:
            break;
        }
    }
}
/*
void Board::setObjectPosition(const float i, const float j)
{
    sf::Vector2f ObjLoc(i,j);
    m_board[i][j]->getImage().setPosition(ObjLoc);
}

    /*
std::vector<std::vector<GameObject>> Board::getBoard()
{
    return m_board;
}*/

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
                    //std::cout << typeid(*m_board[j][i]).name() << std::endl;
                    m_board[j][i]->draw(window);
                   // window.draw(m_board[j][i]->getImage());
                }
            }
        }        
        
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