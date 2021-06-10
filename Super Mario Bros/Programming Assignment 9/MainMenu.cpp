#include "MainMenu.h"

MainMenu::MenuRes MainMenu::Show(sf::RenderWindow& wind)
{
    //load image
    sf::Texture image;
    image.loadFromFile("Textures/Mario Title Screen.png");
    sf::Sprite sprite(image);
    sprite.scale(sf::Vector2f(1.2, 1.2));

    //clickable regions

    //play
    MenuItem playButton;
    sf::RectangleShape play;
    play.setSize(sf::Vector2f(1600, 72));
    play.setPosition(sf::Vector2f(0, 595));
    play.setFillColor(sf::Color::Transparent);
    play.setOutlineColor(sf::Color::Black);
    play.setOutlineThickness(-10);
    playButton.rect.top = 595;
    playButton.rect.width = 1600;
    playButton.rect.left = 0;
    playButton.rect.height = 72;
    playButton.action = Play;

    //exit
    MenuItem exitButton;
    sf::RectangleShape exit;
    exit.setSize(sf::Vector2f(1600, 72));
    exit.setPosition(sf::Vector2f(0, 667));
    exit.setFillColor(sf::Color::Transparent);
    exit.setOutlineColor(sf::Color::Red);
    exit.setOutlineThickness(-10);
    exitButton.rect.top = 667;
    exitButton.rect.width = 1600;
    exitButton.rect.left = 0;
    exitButton.rect.height = 72;
    exitButton.action = Exit;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);

    // Draws specified feature
    wind.draw(sprite);
    wind.draw(play);
    wind.draw(exit);

    wind.display();

    return GetMenuResponse(wind);
}


MainMenu::MenuRes MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;
    for (it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        if (menuItemRect.height + menuItemRect.top > y //bottom
            && menuItemRect.top < y
            && menuItemRect.left < x
            && menuItemRect.left + menuItemRect.width > x) //right
        {
            return (*it).action;
        }
    }
    return Nothing;
}

MainMenu::MenuRes  MainMenu::GetMenuResponse(sf::RenderWindow& wind)
{
    sf::Event menuEvent;
    while (1 != 2)
    {
        while (wind.pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}