#include "Controller.h"
#include <iostream>

const int BUTTONS = 3;

Controller::Controller(int width, int height)
    : m_width(width),
    m_height(height),
    m_window(sf::VideoMode(width, height), "Save The King")
{
}

void Controller::operateGame()
{
    while (m_window.isOpen())
    {
        m_window.clear();
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
                    m_tool.handleToolsClick(location); //create bool to know if the start button is pressed
                    break;
                }
                break;
            }
            }
        }
    }
}