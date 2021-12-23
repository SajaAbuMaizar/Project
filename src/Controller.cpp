#include "Controller.h"
#include "Level.h"
#include <iostream>
#include <fstream>

const int BUTTONS = 3;

Controller::Controller(int width, int height)
    : m_width(width),
    m_height(height),
    m_window(sf::VideoMode(width, height), "Save The King")
{
}

void Controller::operateGame()
{
    sf::Texture background;
    background.loadFromFile("Marvel.jpg");
    auto backgroundImg = sf::Sprite(background);
    while (m_window.isOpen())
    {
        m_window.clear();
        //m_window.draw(backgroundImg);
        for (int counter = 0; counter < BUTTONS; counter++)
        {
            m_window.draw(m_tool.getToolButtons()[counter]);
        }
        m_window.display();
        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: //if the user closes the window then close the window and exit
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased: //if the user pressed the mouse button
            {
                auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left: //if the button that is pressed is the left button
                    if (m_tool.handleToolsClick(location))//if the start button is pressed then enter the loop
                    {
                        Level l;
                        l.levelOperator();
                        //do the start button
                    }
                    break;
                }
                break;
            }
            }
        }
    }
}

