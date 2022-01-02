#include "Help.h"

enum CONSTS { NUM_OF_ICONS = 4, CHAR_SIZE = 30 };
enum Icons { KING, MAGE, WARRIOR, THIEF };

// the c-tor reseives the dimentions of the Help window 
// It inializes the elemnts of the vector m_icons and the elements of vector m_helpText
Help::Help(int width, int hight) :
    m_width(width),
    m_hight(hight)
{
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    m_background.loadFromFile("Background.png");
    m_helpText = fillTextVec("Help");
    fillIconsVec();
}

// this function creates and opens the Help window and prints to it
// the elements of m_helpText and the elements of m_icons.
// the window is opened in waitEvent mode, when the user clicks on one of the icons,
// an Info window is opened to show more info about that icon.
void Help::showHelp()
{
    sf::RenderWindow helpWindow(sf::VideoMode(m_width, m_hight), "Help");
    auto backgroundImg = sf::Sprite(m_background);  // set a background image for helpWindow

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

// helper function, it copies a txt file to a sf::Text vector.
std::vector <sf::Text> Help::fillTextVec(const std::string fileName)
{
    std::ifstream data_file;
    std::string line;
    std::vector <sf::Text> text_vec;

    data_file.open(fileName + ".txt");
    while (!data_file.eof())
    {
        getline(data_file, line);
        text_vec.push_back(sf::Text(line, m_font));
    }
    for (int index = 0; index < text_vec.size(); index++)
    {
        sf::Vector2f linePos(float(0), float(CHAR_SIZE * index));
        text_vec[index].setPosition(linePos);
        text_vec[index].setCharacterSize(20);
    }
    return text_vec;
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
        sf::Vector2f iconLoc(float((m_width / NUM_OF_ICONS) * counter), float(CHAR_SIZE * m_helpText.size())); //CHAR_WIDTH * m_helpText.size() to print the images under the text
        sf::Vector2f iconScale(0.3f, 0.3f);
        m_iconsVec[counter].setPosition(iconLoc);
        m_iconsVec[counter].scale(iconScale);
    }
}

// this function handles the clicks on the characters' icons.
// it desides which character info to send to the showInfo function. 
void Help::handleIconsClick(const sf::Vector2f& location)
{
    std::string info;
    for (int index = 0; index < NUM_OF_ICONS; index++)
    {
        if (m_iconsVec[index].getGlobalBounds().contains(location))
            switch (index)
            {
            case KING: // king icon is pressed
                info = "King";
                break;
            case MAGE: // mage icon is pressed
                info = "Mage";
                break;
            case WARRIOR: // warrior icon is pressed
                info = "Warrior";
                break;
            case THIEF: // theif icon is pressed 
                info = "Thief";
                break;
            }
    }
    showInfo(info);
}

// this function opens a window (in waitEvent mode) when clicking on a character in Help window.
// It shows more information about that character.
void Help::showInfo(const std::string info)
{
    std::vector <sf::Text> info_vec = fillTextVec(info); // read info about the character from a txt file to a vector
    auto backgroundImg = sf::Sprite(m_background);     // set background for infoWindow
    sf::RenderWindow infoWindow(sf::VideoMode(m_width, m_hight), info);

    while (infoWindow.isOpen())
    {
        infoWindow.clear();
        infoWindow.draw(backgroundImg);
        for (int index = 0; index < info_vec.size(); index++)
            infoWindow.draw(info_vec[index]);
        infoWindow.display();

        if (auto event = sf::Event{}; infoWindow.waitEvent(event))
            if (event.type == sf::Event::Closed)
                infoWindow.close();
    }
}