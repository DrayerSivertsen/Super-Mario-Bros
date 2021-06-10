/*
	Programming Language C++

	Programming Assignment 9: A Graphical Game or Application

	Programmers: Drayer Sivertsen, Will Walker, Jack Leeper, and 
	Date Created: 4/20/21
	Last Modified: 4/22/21

	Description: Your goal for the assignment is build a complete graphical, 
	and possibly networked, game or application. As a team you must ultimately 
	decide how you will implement graphics. You have many tools and library 
	options available to implement the graphics portion of the assignment. 
	Some include the Unreal Engine, SFML, Qt, SDL, Allegro, DirectX, OpenGL, 
	etc. Please be sure to also add some directions of how to play the game 
	or use your application.
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "TestCases.h"

int main()
{
	//Initializes All Game functions
	Game Mario;
	//Initializes level music
	sf::Music marioMusic;

	//Plays mario Music for level
	marioMusic.openFromFile("Music/Mario Music.ogg"); 
	marioMusic.play(); //Starts music
	marioMusic.setVolume(10); //Sets volume to 10%

	Mario.runGame();  

	// Test Cases
	//TestCases test;

	// ONLY RUN 1 TEST CASE AT A TIME
	//test.testMainMenuStart();
	//test.testMainMenuExit();
	//test.testDeathByGoomba();
	//test.testDeathByFall();
	//test.testWinGame(); // Close window

	


	return 0;
}