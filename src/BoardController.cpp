#include "BoardController.h"

//this function starts the level, creates the window and prints the level on it
bool BoardController::startLevel(int LevelNum, bool timeLimitedLevel)
{
    std::string titel = "Save The King - Level " + std::to_string(LevelNum);
    sf::RenderWindow window(sf::VideoMode(m_levelSize.x * 45, m_levelSize.y * 45 + 150), titel);//do the enum / 45 = wall height/width / 150 = for the info
    font1.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    //auto backgroundImg = sf::Sprite(m_background);
    LevelData levelData(LevelNum, m_levelSize);
    m_enemyClock.resize(m_enemies.size());
    while (window.isOpen())
    {
        if (m_success)
            window.close();
        window.clear();
        //window.draw(backgroundImg);
        for (size_t j = 0; j < m_levelSize.y; j++)
            for (size_t i = 0; i < m_levelSize.x; i++)
                //ignore nullptr elements and print other elements to the window
                if (m_board[j][i] != nullptr)
                    if (typeid(*m_board[j][i]).name()[6] != 'E')
                        m_board[j][i]->draw(window);

        for (int index = 0; index < m_characters.size(); index++)
            m_characters[index]->draw(window);

        for (int index = 0; index < m_enemies.size(); index++)
        {
            MoveEnemy(index);
            m_enemies[index]->draw(window);
        }
        
        m_clock.getElapsedTime();
        m_TimeLeft = int(m_timer - m_clock.getElapsedTime().asSeconds());
        levelData.initializeData(m_player, m_thiefHasKey, m_TimeLeft, timeLimitedLevel);
        levelData.draw(window, m_clock);
        window.display();
        if (timeLimitedLevel && m_TimeLeft == 0)
        {
            //make a window that tells you to reply
            return m_success;
        }
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

void BoardController::handleKeyPressed(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Key::P:
        m_player = (m_player == 3) ? 0 : m_player + 1;
        break;
    case sf::Keyboard::Key::Down: case sf::Keyboard::Key::Up:
    case sf::Keyboard::Key::Left: case sf::Keyboard::Key::Right:
        handleArrowPressed(key);
        break;
    }
}

void BoardController::MoveEnemy(int enemyIndex)
{
    const auto deltaTime = m_enemyClock[enemyIndex].restart();
    m_enemies[enemyIndex]->setDirection(m_enemies[enemyIndex]->getCurrDir());
    sf::Vector2f pos(m_enemies[enemyIndex]->getPosition().x / 45, m_enemies[enemyIndex]->getPosition().y / 45);
    sf::Vector2f dir(m_enemies[enemyIndex]->getDirection().x, m_enemies[enemyIndex]->getDirection().y);
    sf::Vector2f temp = pos + dir;
    if (round(temp.x) >= m_levelSize.x || round(temp.x) < 0 ||
        round(temp.y) >= m_levelSize.y || round(temp.y) < 0)
        return;
    const char* NextStep = getNextStep(deltaTime, temp);
    //std::cout << NextStep << std::endl;
    if (NextStep[0] != ' ')
    {
        if (m_enemies[enemyIndex]->getCurrDir() == 72)
            m_enemies[enemyIndex]->setCurrDir(71);
        else
            m_enemies[enemyIndex]->setCurrDir(72);
    }
    int moveStatus = m_enemies[enemyIndex]->move(deltaTime, NextStep);
    
    if (NextStep[0] == ' ')
        m_board[round(temp.y)][round(temp.x)] =
            std::move(m_board[round(m_enemies[enemyIndex]->getIndex().y)][round(m_enemies[enemyIndex]->getIndex().x)]);
}

void BoardController::handleArrowPressed(sf::Keyboard::Key key)
{
    const auto deltaTime = m_moveClock.restart();
    m_characters[m_player]->setDirection(key);
    sf::Vector2f pos(m_characters[m_player]->getPosition().x / 45, m_characters[m_player]->getPosition().y / 45);
    sf::Vector2f dir(m_characters[m_player]->getDirection().x * 0.3, m_characters[m_player]->getDirection().y * 0.3);
    sf::Vector2f temp = pos + dir;
    if (round(temp.x) >= m_levelSize.x || round(temp.x) < 0 ||
        round(temp.y) >= m_levelSize.y || round(temp.y) < 0)
        return;
    const char* NextStep = getNextStep(deltaTime, temp);
    int moveStatus = m_characters[m_player]->move(deltaTime, NextStep);
    switch (moveStatus)
    {
    case S_FIRE:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        break;
    case S_ORC:
        m_board[round(temp.y)][round(temp.x)] = std::make_unique<Key>(m_textures[10], float(round(temp.x)), float(round(temp.y)));
        break;
    case S_KEY:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_thiefHasKey = true;
        break;
    case S_GATE:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_thiefHasKey = false;
        break;
    case S_CHAIR:
        m_success = true;
        break;
    case S_TELE:
        for (int index = 0; index < m_TeleportCells.size(); index++)
        {
            sf::Vector2f Ttemp(round(temp.x) * 45, round(temp.y) * 45);
            if (m_TeleportCells[index]->initializeImg().getPosition() == Ttemp)
            {
                int SecondTeleportIndex = (index % 2 == 0) ? index + 1 : index - 1 ;
                sf::Vector2f characterPos(m_TeleportCells[SecondTeleportIndex]->initializeImg().getPosition().x - 10,
                    m_TeleportCells[SecondTeleportIndex]->initializeImg().getPosition().y - 10);
                m_characters[m_player]->initializeImg().setPosition(characterPos);
            }
        }
        break;
    case S_KILL_PRESENT:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_enemies.clear();
        break;
    case 8:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_timer += 5;
        break;
    case 9:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_timer -= 5;
        break;
    }
}
const char* BoardController::getNextStep(sf::Time deltaTime, sf::Vector2f temp)
{
    const char* NextStep = " ";
    if (m_board[round(temp.y)][round(temp.x)] != nullptr)
        NextStep = typeid(*m_board[round(temp.y)][round(temp.x)]).name();
    for (int index = 0 ; index < m_enemies.size(); index++)
    {
        sf::Vector2f temp2 = m_enemies[index]->getPosition() / 45.0f;
            if (temp2.x - 0.5f <= temp.x && temp.x <= temp2.x + 0.5f &&
                temp2.y - 0.5f <= temp.y && temp.y <= temp2.y + 0.5f)
            NextStep = "class Enemy";
    }

    return NextStep;
}