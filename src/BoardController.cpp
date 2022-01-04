#include "BoardController.h"

//this function starts the level, creates the window and prints the level on it
void BoardController::startLevel()
{
    sf::RenderWindow window(sf::VideoMode(m_levelSize.x * 45, m_levelSize.y * 45 + 100), "Save The King Level ");//do the enum / 45 = wall height/width / 100 = for the info
    font1.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    m_enemyClock.resize(m_enemies.size());
    while (window.isOpen())
    {
        if (m_success)
            window.close();

        //std::cout << m_enemies.size() << std::endl;
       // for (int index = 0 ; index < m_enemies.size(); index++)
     //   {
     //       MoveEnemy(index);
     //   }
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
        for (int index = 0; index < m_enemies.size(); index++)
        {
            MoveEnemy(index);
            //m_enemies[index]->draw(window);
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
    static int currDir = 72;
    const auto deltaTime = m_enemyClock[enemyIndex].restart();
    
    sf::Vector2f pos(m_enemies[enemyIndex]->getPosition().x / 45, m_enemies[enemyIndex]->getPosition().y / 45);
    sf::Vector2f dir(m_enemies[enemyIndex]->getDirection().x * 0.3, m_enemies[enemyIndex]->getDirection().y * 0.3);
    sf::Vector2f temp = pos + dir;
    if (round(temp.x) >= m_levelSize.x || round(temp.x) < 0 ||
        round(temp.y) >= m_levelSize.y || round(temp.y) < 0)
        return;
    const char* NextStep = getNextStep(deltaTime, temp);
    if (NextStep[0] != ' ')
    {
        if (currDir == 72)
            currDir = 71;
        else
            currDir = 72;
    }
    m_enemies[enemyIndex]->setDirection(currDir);
    int moveStatus = m_enemies[enemyIndex]->move(deltaTime, NextStep);
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
    case 1:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        break;
    case 2:
        m_board[round(temp.y)][round(temp.x)] = std::make_unique<Key>(m_textures[10], float(round(temp.x)), float(round(temp.y)));
        break;
    case 3:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_thiefHasKey = true;
        break;
    case 4:
        m_board[round(temp.y)][round(temp.x)] = nullptr;
        m_thiefHasKey = false;
        break;
    case 5:
        m_success = true;
        break;
    case 6:
        for (int index = 0; index < m_TeleportCells.size(); index++)
        {
            sf::Vector2f Ttemp(round(temp.x) * 45, round(temp.y) * 45);
            if (m_TeleportCells[index]->initializeImg().getPosition() == Ttemp)
            {
                if (index % 2 == 0)
                {
                    sf::Vector2f characterPos(m_TeleportCells[index + 1]->initializeImg().getPosition().x - 10,
                        m_TeleportCells[index + 1]->initializeImg().getPosition().y - 10);
                    m_characters[m_player]->initializeImg().setPosition(characterPos);
                }
                else
                {
                    sf::Vector2f characterPos(m_TeleportCells[index - 1]->initializeImg().getPosition().x - 10,
                        m_TeleportCells[index - 1]->initializeImg().getPosition().y - 10);
                    m_characters[m_player]->initializeImg().setPosition(characterPos);
                }
            }
        }
        break;
    }
}
const char* BoardController::getNextStep(sf::Time deltaTime, sf::Vector2f temp)
{
    const char* NextStep = " ";
    if (m_board[round(temp.y)][round(temp.x)] != nullptr)
    {
        NextStep = typeid(*m_board[round(temp.y)][round(temp.x)]).name();
    }

    return NextStep;
}