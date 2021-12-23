#include "Board.h"
#include <iostream>

void Board::readLevel(std::ifstream& board_file)
{
    std::string line;
    board_file.seekg(0); //erturn to the beginning of the file
    getline(board_file, line);
    getline(board_file, line);
    //start reading the level
    char c;
    while (!board_file.eof())
    {
        for (size_t i = 0; i < m_levelSize.x; i++)
        {
            for (size_t j = 0; j < m_levelSize.y; j++)
            {
                c = char(board_file.get());
                readChar(c, i, j);
            }
        }
    }
}

void Board::readChar(const char c, const size_t i, const size_t j)
{
    std::cout << c << " " << i << " " << j << std::endl;

    m_board.resize(m_levelSize.x);
    for (int i = 0; i < m_levelSize.x; i++)
        m_board[i].resize(m_levelSize.y);
    
    switch (c)
    {
    case '=':
        m_board[i][j] = std::make_unique<Wall>(float(i),float(j));
        break;
    case '*':
        m_board[i][j] = std::make_unique<Fire>(float(i), float(j));
        break;
    case '!':
        m_board[i][j] = std::make_unique<Orc>(float(i), float(j));
        break;
    case '#':
        m_board[i][j] = std::make_unique<Gate>(float(i), float(j));
        break;
    case 'X':
        m_board[i][j] = std::make_unique<TeleportCell>(float(i), float(j));
        break;
    case '@':
        m_board[i][j] = std::make_unique<KingChair>(float(i), float(j));
    }
}
    /*
std::vector<std::vector<GameObject>> Board::getBoard()
{
    return m_board;
}*/

void Board::startLevel()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Save The King Level ");
    font1.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    while (window.isOpen())
    {
        window.clear();
        for (unsigned int i = 0; i < m_levelSize.x; i++)
        {
            for (unsigned int j = 0; j < m_levelSize.y; j++)
            {
                //window.draw(m_board[i][j]->draw()); //this is the problematic line
            }
        }
        /*
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
        */
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