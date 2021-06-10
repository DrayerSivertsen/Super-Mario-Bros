#pragma once

//Includes
#include "MainMenu.h"
#include "Character.h"
#include "PhysicalProperties.h"
#include "Goomba.h"

class Game : public PhysicalProps //Inherits from PhysicalProps class so we can check collision with platforms
{
public:
	Game();
	~Game();

/*
Function: Run Game
Date Created: 4/20/21
Date Last Modified: 4/29/21
Description: The function runs the game loop and keeps track of all necessary updates
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void runGame(); //Runs the Game


protected:
	sf::RenderWindow window; //Where we draw everything to
	//mainMenu
	bool showMainMenu(); //Shows main menu

	sf::Font MyFont;

	// World Background
	sf::Sprite worldBackground;
	sf::Texture worldBackgroundTexture;

	// Game over screen
	sf::Sprite gameOverScreen;
	sf::Texture gameOverScreenTexture;

	//Player
	Character* mario;

	//Enemies
	
	Goombas* goomba1;
	//Between 1st & 2nd Pipe
	Goombas* goomba2;
	//Between 3rd & 4th Pipes
	Goombas* goomba3;
	Goombas* goomba4;
	//Between 2nd to last pipe and last pipe
	Goombas* goomba5;
	Goombas* goomba6;
	Goombas* goomba7;


	void updateMario(); //Updates Mario
	void updateSingleGoomba(Goombas *goomba); //Updates single Goomba
	void updateGoombas(); //Calls single function for all Goombas

	// functions

/*
Functions: Check collision
Date Created: 4/20/21
Date Last Modified: 4/29/21
Description: The functions checks for collisions between the player and game structures as well as the ground
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void checkAllCollision();
	void checkGroundCollision();

/*
Functions: Check enemy collisions
Date Created: 4/20/21
Date Last Modified: 4/29/21
Description: The functions checks player collisions with enemies 
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	bool checkEnemyCollision();
	bool CheckGoombaCollision();

/*
Functions: Initalization
Date Created: 4/20/21
Date Last Modified: 4/29/21
Description: The functions initialize the games screens, characters and music
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void initWindow();
	void initWorldBackground();
	void initMarioCharacter();
	void initGoombas();
	void initGameOverScreen();

/*
Functions: Render
Date Created: 4/20/21
Date Last Modified: 4/29/21
Description: The functions draw the specified game component and are all called in render
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void render(); //Call all other render functions and draws to screen
	void renderWorldBackground();
	void renderMarioCharacter();
	void renderGoombas();
	void renderGameOverScreen();

};

