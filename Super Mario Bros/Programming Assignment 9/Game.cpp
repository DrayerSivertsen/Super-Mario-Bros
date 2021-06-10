#include "Game.h"


Game::Game() //Calls intializers
{
	this->initWindow();
	this->initWorldBackground();
	this->initMarioCharacter();
	this->initGoombas();
	this->initGameOverScreen();
}

Game::~Game() //Deletes all created entities
{
	delete this->mario;
	delete this->goomba1;
	delete this->goomba2;
	delete this->goomba3;
	delete this->goomba4;
	delete this->goomba5;
	delete this->goomba6;
	delete this->goomba7;

}

void Game::runGame()
{
	//Creates a message for winning the game
	MyFont.loadFromFile("MyFont.ttf");

	sf::Text text;
	text.setFont(MyFont);
	text.setString("congratulations you win!");
	text.setCharacterSize(165);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(11100, 20));
	//text.setStyle(sf::Text::Style::Bold);
	
	//Sets velocity = 0
	sf::Vector2f velocity(sf::Vector2f(0.f, 0.f));

	if (showMainMenu() == true)
	{
		while (this->window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyReleased &&
					(event.key.code == sf::Keyboard::A ||
						event.key.code == sf::Keyboard::D ||
						event.key.code == sf::Keyboard::W ||
						event.key.code == sf::Keyboard::S))
				{
					this->mario->resetAnimationTimer();
				}
			}

			//Checks collision for mario
			this->checkAllCollision();
			this->checkGroundCollision();

			//Variables for telling if game is over
			bool gameOver = false;

			if (this->checkEnemyCollision()) //Ends Game is mario collides with enemy
			{
				gameOver = true;
			}

			if (mario->getPosition().y > 1000) //If mario falls to death ends game
			{
				gameOver = true;
			}

			if (gameOver) //If game is over
			{

				sf::View view;
				sf::Vector2i screenDimensions(1600, 900);
				window.clear();
				renderGameOverScreen(); //Play deathscreen
				window.setView(window.getDefaultView()); //Sets camera to default position
				
			}
			else //If game is not over
			{
				
				this->updateMario(); //Update mario
				this->updateGoombas(); //Update goombas

				this->render(); //Draw everything

				if (mario->getCharSprite().getPosition().x > 11900) //If mario is at castle, Print text
				{
					window.draw(text);
				}
			}

			window.display();
		}
	}
}

//show mainMenu
bool Game::showMainMenu()
{
	MainMenu main;
	MainMenu::MenuRes result = main.Show(this->window); //Gets if you should exit game or start game
	do
	{
		if (result == 2) //play game
		{
			return true;
		}
		else if (result == 1) //exit
		{
			return false;
		}

		result = main.Show(this->window);
	} while (result != 2  && result != 1);
}

void Game::initWindow() //Creates Window
{
	this->window.create(sf::VideoMode(1600, 900), "SFML MARIO");
	this->window.setFramerateLimit(60);
}

void Game::initGameOverScreen() //Creates game over screen
{
	gameOverScreenTexture.loadFromFile("Textures/Gameover.jpg");
	gameOverScreen.setTexture(this->gameOverScreenTexture);
	gameOverScreen.scale(sf::Vector2f(1.05, 1.05));
}

void Game::initWorldBackground() //Creates Background
{
	this->worldBackgroundTexture.loadFromFile("Textures/Mario Background 1-1.png");

	this->worldBackground.setTexture(this->worldBackgroundTexture);

	this->worldBackground.setScale(sf::Vector2f(3.75, 3.75));
}

void Game::initMarioCharacter() //Creates mario players
{
	this->mario = new Character(); //Makes mario
}

void Game::updateMario()
{
	this->mario->updateCharacter(this->window); //UpdatesMario
	
}

//Add new Goombas
void Game::initGoombas()
{
	this->goomba1 = new Goombas(sf::Vector2f(400, 730)); //Initiates Goomba to position(400,730)
	this->goomba2 = new Goombas(sf::Vector2f(2000, 730));//Initiates Goomba to position(2000,730)
	this->goomba3 = new Goombas(sf::Vector2f(3000, 730));
	this->goomba4 = new Goombas(sf::Vector2f(3300, 730));
	this->goomba5 = new Goombas(sf::Vector2f(9900, 730));
	this->goomba6 = new Goombas(sf::Vector2f(10300, 730));
	this->goomba7 = new Goombas(sf::Vector2f(10700, 730));
}

void Game::updateGoombas() //Updates All Goombas
{
	updateSingleGoomba(goomba1); 
	updateSingleGoomba(goomba2);
	updateSingleGoomba(goomba3);
	updateSingleGoomba(goomba4);
	updateSingleGoomba(goomba5);
	updateSingleGoomba(goomba6);
	updateSingleGoomba(goomba7);
}
void Game::renderGoombas() //Renders All Goombas
{
	this->goomba1->renderGoombas(this->window);
	this->goomba2->renderGoombas(this->window);
	this->goomba3->renderGoombas(this->window);
	this->goomba4->renderGoombas(this->window);
	this->goomba5->renderGoombas(this->window);
	this->goomba6->renderGoombas(this->window);
	this->goomba7->renderGoombas(this->window);
}

bool Game::CheckGoombaCollision() //Checks if All goombas have had a collision
{
	bool marioDead = false;

	if (goomba1->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	if (goomba2->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	if (goomba3->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	if (goomba4->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	if (goomba5->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	if (goomba6->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	if (goomba7->checkGoombaPlayerCollision(mario->getCharSprite(), this->window))
	{
		marioDead = true; //If mario collides, Mario dies
	}
	//Checks Goomba2 Collision
	goomba2->checkGoombaCollision(tube1);
	goomba2->checkGoombaCollision(tube2);
	goomba3->checkGoombaCollision(tube3);
	goomba3->checkGoombaCollision(tube4);
	goomba4->checkGoombaCollision(tube3);
	goomba4->checkGoombaCollision(tube4);
	goomba5->checkGoombaCollision(tube5);
	goomba5->checkGoombaCollision(tube6);
	goomba6->checkGoombaCollision(tube5);
	goomba6->checkGoombaCollision(tube6);
	goomba7->checkGoombaCollision(tube5);
	goomba7->checkGoombaCollision(tube6);
	return marioDead; //Returns if mario died
}


void Game::updateSingleGoomba(Goombas *goomba) //Updates 1 goomba, pass in the goomba
{
	goomba->movement();
	goomba->updateAnimations();
}

//Draws entities and background
void Game::render()
{
	this->window.clear();

	// World
	this->renderWorldBackground();

	// Mario
	this->renderMarioCharacter();

	//Goombas
	this->renderGoombas();
}

void Game::renderWorldBackground() //draws background
{
	this->window.draw(this->worldBackground);
}

void Game::renderGameOverScreen() //Draws gameOverScreen
{
	this->window.draw(this->gameOverScreen);
}

void Game::renderMarioCharacter() //Draws Mario
{
	this->mario->renderChar(this->window);
}

bool Game::checkEnemyCollision() //Checks If mario has collision with everything
{
	bool marioDead = false;

	if (this->CheckGoombaCollision())
	{
		marioDead = true;
	}

	return marioDead;
}


void Game::checkGroundCollision() //Checks player collision with ground
{
	mario->checkGroundCollision(this->ground1);
	mario->checkGroundCollision(this->ground2);
	mario->checkGroundCollision(this->ground3);
	mario->checkGroundCollision(this->ground4);
}

void Game::checkAllCollision() //Checks Player collision with flag and Platforms
{
	//Flag
	mario->checkFlagPoleCollision(this->flagHitbox);

	//Pipes
	mario->checkPlayerCollision(this->tube1);
	mario->checkPlayerCollision(this->tube2);
	mario->checkPlayerCollision(this->tube3);
	mario->checkPlayerCollision(this->tube4);
	mario->checkPlayerCollision(this->tube5);
	mario->checkPlayerCollision(this->tube6);

	//Stairs
	mario->checkPlayerCollision(this->sb1);
	mario->checkPlayerCollision(this->sb2);
	mario->checkPlayerCollision(this->sb3);
	mario->checkPlayerCollision(this->sb4);
	mario->checkPlayerCollision(this->sb5);
	mario->checkPlayerCollision(this->sb6);
	mario->checkPlayerCollision(this->sb7);
	mario->checkPlayerCollision(this->sb8);
	mario->checkPlayerCollision(this->sb9);
	mario->checkPlayerCollision(this->sb10);
	mario->checkPlayerCollision(this->sb11);
	mario->checkPlayerCollision(this->sb12);
	mario->checkPlayerCollision(this->sb13);
	mario->checkPlayerCollision(this->sb14);
	mario->checkPlayerCollision(this->sb15);
	mario->checkPlayerCollision(this->sb16);
	mario->checkPlayerCollision(this->sb17);
	mario->checkPlayerCollision(this->sb18);
	mario->checkPlayerCollision(this->sb19);
	mario->checkPlayerCollision(this->sb20);
	mario->checkPlayerCollision(this->sb21);
	mario->checkPlayerCollision(this->sb22);
	mario->checkPlayerCollision(this->sb23);
	mario->checkPlayerCollision(this->sb24);
	mario->checkPlayerCollision(this->sb25);
	mario->checkPlayerCollision(this->sb26);
	mario->checkPlayerCollision(this->sb27);

	//MysteryBoxes
	//row1
	mario->checkPlayerCollision(this->mb1);
	mario->checkPlayerCollision(this->mb2);
	mario->checkPlayerCollision(this->mb3);
	mario->checkPlayerCollision(this->mb4);
	mario->checkPlayerCollision(this->mb5);
	mario->checkPlayerCollision(this->mb6);
	mario->checkPlayerCollision(this->mb7);
	mario->checkPlayerCollision(this->mb8);

	mario->checkPlayerCollision(this->mb9);
	mario->checkPlayerCollision(this->mb10);
	mario->checkPlayerCollision(this->mb11);
	mario->checkPlayerCollision(this->mb12);
	mario->checkPlayerCollision(this->mb13);

	//Bricks
	//Row1
	mario->checkPlayerCollision(this->bb1);
	mario->checkPlayerCollision(this->bb2);
	mario->checkPlayerCollision(this->bb3);
	mario->checkPlayerCollision(this->bb4);
	mario->checkPlayerCollision(this->bb5);
	mario->checkPlayerCollision(this->bb6);
	mario->checkPlayerCollision(this->bb7);
	mario->checkPlayerCollision(this->bb8);
	mario->checkPlayerCollision(this->bb9);
	mario->checkPlayerCollision(this->bb10);
	mario->checkPlayerCollision(this->bb11);
	mario->checkPlayerCollision(this->bb12);
	mario->checkPlayerCollision(this->bb13);

	//Row2
	mario->checkPlayerCollision(this->bb14);
	mario->checkPlayerCollision(this->bb15);
	mario->checkPlayerCollision(this->bb16);
	mario->checkPlayerCollision(this->bb17);
	mario->checkPlayerCollision(this->bb18);
	mario->checkPlayerCollision(this->bb19);
	mario->checkPlayerCollision(this->bb20);
	mario->checkPlayerCollision(this->bb21);
	mario->checkPlayerCollision(this->bb22);
	mario->checkPlayerCollision(this->bb23);
	mario->checkPlayerCollision(this->bb24);
	mario->checkPlayerCollision(this->bb25);
	mario->checkPlayerCollision(this->bb26);
	mario->checkPlayerCollision(this->bb27);
	mario->checkPlayerCollision(this->bb28);
	mario->checkPlayerCollision(this->bb29);
	mario->checkPlayerCollision(this->bb30);

}