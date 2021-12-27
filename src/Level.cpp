#include "Level.h"
#include "Board.h"

enum CONSTS { NUM_0F_LEVELS = 3 };
Level::Level() :
    m_level(1),
    m_timer(0),
    m_levelSize(0,0)
{}

void Level::buildLevel()
{
    std::ifstream board_file;
    createFileName();
    board_file.open(m_fileName);
    if (!board_file) //if opening the file faild. . .
    {
        std::cerr << "Error: File could NOT be opened !!!";
        exit(1);
    }
    std::string time_str;
    getline(board_file, time_str);
    if (time_str == "T") // T = time limited level, F = not time limited
    {
        getline(board_file, time_str);
        std::stringstream geek(time_str);
        float levelTimer;
        geek >> levelTimer; //the time from string to float
        m_timer = levelTimer;
    }
    else
    {
        getline(board_file, time_str); //ignore a line
    }
    calculateLevelSize(board_file);
    Board b(m_levelSize, m_timer, m_clock);
    b.readLevel(board_file);
    b.startLevel();
}

std::string Level::createFileName()
{
    return (std::to_string(m_level) + ".txt");
}

void Level::levelOperator()
{
    for (; m_level <= NUM_0F_LEVELS; m_level++)
    {
        m_levelSize.x = m_levelSize.y = 0;
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
        m_levelSize.y++;
        m_levelSize.x = ((line.size() > m_levelSize.x) ? unsigned int(line.size()) : m_levelSize.x);
    }
}