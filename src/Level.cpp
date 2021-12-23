#include "Level.h"
#include "Board.h"

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
    if (time_str == "T") //time limited level
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
    std::cout << m_levelSize.x << " " << m_levelSize.y << std::endl;//
    Board b(m_levelSize);
    b.readLevel(board_file);
    std::cout << "here\n";
    b.startLevel();
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

