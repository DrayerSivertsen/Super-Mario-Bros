#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>

class MainMenu
{
public:
	enum MenuRes { Nothing, Exit, Play };
	struct MenuItem
	{
		sf::Rect<int> rect;
		MenuRes action;
	};

	MenuRes Show(sf::RenderWindow& wind);

private:
	MenuRes GetMenuResponse(sf::RenderWindow& wind);
	MenuRes HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};

//class Menu
//{
//public:
//	Menu(float width, float height);
//	~Menu();

//}