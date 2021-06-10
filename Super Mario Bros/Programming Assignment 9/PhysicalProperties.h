#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <Shape.hpp>
#define ground2X 4260 //Distance in x direction of 2nd ground platform
#define ground3X 5340 //Distance in x direction of 3rd ground platform
#define ground4X 9300 //Distance in x direction of 4th ground platform

class PhysicalProps 
{
public:
	PhysicalProps();
	//~PhysicalProps();

	void render(sf::RenderTarget& target); //Draws all platforms

protected:
	
	//All Ground
	sf::RectangleShape ground1;
	sf::RectangleShape ground2;
	sf::RectangleShape ground3;
	sf::RectangleShape ground4;

	//All Tubes
	sf::RectangleShape tube1;
	sf::RectangleShape tube2;
	sf::RectangleShape tube3;
	sf::RectangleShape tube4;
	sf::RectangleShape tube5;
	sf::RectangleShape tube6;

	//All Stairs
	sf::RectangleShape sb1;
	sf::RectangleShape sb2;
	sf::RectangleShape sb3;
	sf::RectangleShape sb4;
	sf::RectangleShape sb5;
	sf::RectangleShape sb6;
	sf::RectangleShape sb7;
	sf::RectangleShape sb8;
	sf::RectangleShape sb9;
	sf::RectangleShape sb10;
	sf::RectangleShape sb11;
	sf::RectangleShape sb12;
	sf::RectangleShape sb13;
	sf::RectangleShape sb14;
	sf::RectangleShape sb15;
	sf::RectangleShape sb16;
	sf::RectangleShape sb17;
	sf::RectangleShape sb18;
	sf::RectangleShape sb19;
	sf::RectangleShape sb20;
	sf::RectangleShape sb21;
	sf::RectangleShape sb22;
	sf::RectangleShape sb23;
	sf::RectangleShape sb24;
	sf::RectangleShape sb25;
	sf::RectangleShape sb26;
	sf::RectangleShape sb27;

	//All mysteryBoxes
	sf::RectangleShape mb1;
	sf::RectangleShape mb2;
	sf::RectangleShape mb3;
	sf::RectangleShape mb4;
	sf::RectangleShape mb5;
	sf::RectangleShape mb6;
	sf::RectangleShape mb7;
	sf::RectangleShape mb8;
	//Second row
	sf::RectangleShape mb9;
	sf::RectangleShape mb10;
	sf::RectangleShape mb11;
	sf::RectangleShape mb12;
	sf::RectangleShape mb13;

	//All Bricks
	sf::RectangleShape bb1;
	sf::RectangleShape bb2;
	sf::RectangleShape bb3;
	sf::RectangleShape bb4;
	sf::RectangleShape bb5;
	sf::RectangleShape bb6;
	sf::RectangleShape bb7;
	sf::RectangleShape bb8;
	sf::RectangleShape bb9;
	sf::RectangleShape bb10;
	sf::RectangleShape bb11;
	sf::RectangleShape bb12;
	sf::RectangleShape bb13;

	//Second row
	sf::RectangleShape bb14;
	sf::RectangleShape bb15;
	sf::RectangleShape bb16;
	sf::RectangleShape bb17;
	sf::RectangleShape bb18;
	sf::RectangleShape bb19;
	sf::RectangleShape bb20;
	sf::RectangleShape bb21;
	sf::RectangleShape bb22;
	sf::RectangleShape bb23;
	sf::RectangleShape bb24;
	sf::RectangleShape bb25;
	sf::RectangleShape bb26;
	sf::RectangleShape bb27;
	sf::RectangleShape bb28;
	sf::RectangleShape bb29;
	sf::RectangleShape bb30;

	//Flag
	sf::RectangleShape flagHitbox;
};

