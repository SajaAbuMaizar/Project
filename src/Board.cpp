#include "Board.h"
#include <iostream>

void Board::readLevel(std::ifstream& board_file)
{
    char c;
    std::string line;

    //go back to the beginning of the file
    board_file.seekg(0);

    //ignor two lines (the sketch of the board starts from the 3rd line)
    getline(board_file, line);
    getline(board_file, line);

    //start reading the level
    while (!board_file.eof())
    {
        //for (size_t j = 2; j < m_levelSize.y ;j++) // start from line 2 (disclude two lines of data about timeLimited) [didn't used because we need j to start from 0 because we use it]
        for (size_t j = 0; j < m_levelSize.y; j++)
        {
            for (size_t i = 0; i < m_levelSize.x; i++)
            {
                size_t temp = j;
                c = char(board_file.get());
                readChar(c, i, j);
                if (temp != j)
                {
                    break;
                }
            }
        }
        std::cout << "finished reading file\n";   // it prints this line
    }
    std::cout << "exiting readLevel func\n"; //  it doesn't print this line
}

void Board::readChar(const char c, const size_t i, size_t& j)
{
    std::cout << c << " " << i << " " << j << std::endl;

    // m_board[m_levelSize.x][m_levelSize.y]
    m_board.resize(m_levelSize.y);

    for (unsigned int index = 0; index < m_levelSize.y; index++)
        m_board[index].resize(m_levelSize.x);
    
    switch (c)
    {
    case '=':
        m_board[j][i] = std::make_unique<Wall>(float(i),float(j));
        break;
    case '*':
        m_board[j][i] = std::make_unique<Fire>(float(i), float(j));
        break;
    case '!':
        m_board[j][i] = std::make_unique<Orc>(float(i), float(j));
        break;
    case '#':
        m_board[j][i] = std::make_unique<Gate>(float(i), float(j));
        break;
    case 'X':
        m_board[j][i] = std::make_unique<TeleportCell>(float(i), float(j));
        break;
    case '@':
        m_board[j][i] = std::make_unique<KingChair>(float(i), float(j));
        break;
    case '\n':
        m_board[j][i] = std::make_unique<KingChair>(float(i), float(j));
        j++;
        break;
    default:
        //m_board[j][i] = nullptr;
        break;
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

void Board::startLevel()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Save The King Level ");
    font1.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    while (window.isOpen())
    {
        window.clear();
        for (size_t j = 0; j < m_levelSize.y; j++)
        {
            for (size_t i = 0; i < m_levelSize.x; i++)
            {
                std::cout << "befor if condition\n";
                //ignore nullptr elements and print other elements to the window
                if (m_board[j][i] != nullptr)
                {
                    std::cout << "in if\n";
                    window.draw(m_board[j][i]->getImage());
                }
            }
        }
        /*
        for (unsigned int i = 0; i < m_levelSize.x; i++)
        {
            for (unsigned int j = 0; j < m_levelSize.y; j++)
            {
                //ignore nullptr elements and print other elements to the window
                if (m_board[j][i] != nullptr)
                    window.draw(m_board[j][i]->getImage());
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