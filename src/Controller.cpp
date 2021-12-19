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
    std::cout << "here\n";
    ToolBar tool;
    while (m_window.isOpen())
    {
        m_window.clear();
        for (int counter = 0; counter < BUTTONS; counter++)
        {
            m_window.draw(tool.getToolButtons()[counter]);
        }
        m_window.display();
        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: //if the user closes the window then close the window and exit
                m_window.close();
                break;
            }
        }
    }
}