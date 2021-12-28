#include "Help.h"

enum CONSTS { NUM_OF_ICONS = 4, CHAR_WIDTH = 30};
enum Icons {KING, MAGE, WARRIOR, THIEF};

// the c-tor reseives the dimentions of the Help window 
// It inializes the elemnts of the vector m_icons and the elements of vector m_helpText
Help::Help(int width, int hight) :
    m_width(width),
    m_hight(hight)
{
    fillHelpTextVec();
    fillIconsVec();
}

// this function creates and opens the Help window and prints to it
// the elements of m_helpText and the elements of m_icons.
// the window is opened in waitEvent mode, when the user clicks on one of the icons,
// an Info window is opened to show more info about that icon.
void Help::showHelp()
{
    sf::RenderWindow helpWindow(sf::VideoMode(m_width, m_hight), "Help");

    // set background for helpWindow
    m_background.loadFromFile("Background.png");
    auto backgroundImg = sf::Sprite(m_background);

    while (helpWindow.isOpen())
    {
        helpWindow.clear();
        helpWindow.draw(backgroundImg);
        for (int index = 0; index < m_helpText.size(); index++)
            helpWindow.draw(m_helpText[index]);
        
        for (int index = 0; index < m_iconsVec.size(); index++)
            helpWindow.draw(m_iconsVec[index]);

        helpWindow.display();

        if (auto event = sf::Event{}; helpWindow.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                helpWindow.close();
                break;

            case sf::Event::MouseButtonReleased: //if the user pressed the mouse button
                auto location = helpWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                handleIconsClick(location);
                break;
            }
        }
    }
}

// helper function for the c-tor, it creates the elements of m_helpText.
void Help::fillHelpTextVec()
{
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

    m_helpText.push_back(sf::Text("To switch between the character press p.\n", m_font));
    m_helpText.push_back(sf::Text("To move right press the right arrow.\n", m_font));
    m_helpText.push_back(sf::Text("To move left press the left arrow.\n", m_font));
    m_helpText.push_back(sf::Text("To move up press the up arrow.\n", m_font));
    m_helpText.push_back(sf::Text("To move down press the down arrow.\n", m_font));
    m_helpText.push_back(sf::Text("Press on a character for more information about it.\n", m_font));
    m_helpText.push_back(sf::Text("Press the X icon to exit the Help window.\n", m_font));

    
    for (int index = 0; index < m_helpText.size(); index++)
    {
        sf::Vector2f linePos(float(0), float(CHAR_WIDTH * index));
        m_helpText[index].setPosition(linePos);
        m_helpText[index].setCharacterSize(20);
    }
}

// helper function for the c-tor, it creates the elements of m_icons which is a vector of
// sf::Sprite elements that represent characters in the game.
void Help::fillIconsVec()
{
    m_kingTex.loadFromFile("King.png");
    auto kingImg = sf::Sprite(m_kingTex);
    m_iconsVec.push_back(kingImg);

    m_mageTex.loadFromFile("Mage.png");
    auto mageImg = sf::Sprite(m_mageTex);
    m_iconsVec.push_back(mageImg);

    m_warriorTex.loadFromFile("Warrior.png");
    auto warriorImg = sf::Sprite(m_warriorTex);
    m_iconsVec.push_back(warriorImg);

    m_thiefTex.loadFromFile("Thief.png");
    auto thiefImg = sf::Sprite(m_thiefTex);
    m_iconsVec.push_back(thiefImg);

    for (int counter = 0; counter < m_iconsVec.size(); counter++)
    {
        sf::Vector2f iconLoc(float((m_width / NUM_OF_ICONS) * counter), float(CHAR_WIDTH * m_helpText.size())); //CHAR_WIDTH * m_helpText.size() to print the picture under the text
        sf::Vector2f iconScale(0.3f, 0.3f);
        m_iconsVec[counter].setPosition(iconLoc);
        m_iconsVec[counter].scale(iconScale);
    }
}

// this function handles the clicks on the characters' icons.
// it desides which character info to send to the showInfo function. 
void Help::handleIconsClick(const sf::Vector2f& location)
{
    sf::Text info;
    info.setFont(m_font);
    for (int index = 0; index < NUM_OF_ICONS; index++)
    {
        if (m_iconsVec[index].getGlobalBounds().contains(location))
        {
            switch (index)
            {
            case KING: // king icon is pressed
                info.setString("king");
                break;
            case MAGE: // mage icon is pressed
                info.setString("mage");
                break;
            case WARRIOR: // warrior icon is pressed
                info.setString("warrior");
                break;
            case THIEF: // theif icon is pressed 
                info.setString("thief");
                break;
            }
        }
    }
    showInfo(info);
}

// this function opens a window (in waitEvent mode) when clicking on a character in Help window,
// it shows more information about that character.
void Help::showInfo(const sf::Text info)
{
    // set background for helpWindow
    auto backgroundImg = sf::Sprite(m_background);

    sf::RenderWindow infoWindow(sf::VideoMode(m_width,m_hight), "More Info");

    while (infoWindow.isOpen())
    {
        infoWindow.clear();
        infoWindow.draw(backgroundImg);
        infoWindow.draw(info);
        infoWindow.display();

        if (auto event = sf::Event{}; infoWindow.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                infoWindow.close();
                break;
            }
        }
    }
}