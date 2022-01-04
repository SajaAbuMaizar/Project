#include <typeinfo>
#include <iostream>
#include "Board.h"

Board::Board() : m_player(0), m_timer(0), m_thiefHasKey(false), m_success(false)
{
    m_textures.resize(12); //6 = number of characters
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
    m_textures[10].loadFromFile("Key.png");
    m_textures[11].loadFromFile("Enemy.png");
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
            m_TeleportCells.emplace_back(std::make_unique<TeleportCell>(m_textures[4], float(i), float(j)));
            break;
        case '@':
            m_board[j][i] = std::make_unique<Chair>(m_textures[2], float(i), float(j));
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
        case '^':
            m_enemies.push_back(std::make_unique<Thief>(m_textures[11], float(i), float(j)));
            break;
        default:
            break;
        }
    }
}
