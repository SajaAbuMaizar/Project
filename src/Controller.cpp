#include "Controller.h"

Controller::Controller(int width, int height)
    : m_width(width),
    m_height(height),
    m_window(sf::VideoMode(width, height), "Save The King")
{
    while (m_window.isOpen())
    {
        m_window.clear();
        //draw tool bar
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

void Controller::operateGame()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        //draw tool bar
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