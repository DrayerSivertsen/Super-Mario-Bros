#include "TestCases.h"



//Tests the main menu start game button
void TestCases::testMainMenuStart()
{

	MainMenu main;
	MainMenu::MenuRes result = main.Show(this->window); //Gets if you should exit game or start game
	do
	{
		if (result == 2) //play game
		{
			std::cout << "Test case main menu start Successful!" << std::endl;
			window.close();
		}
		else
		{
			std::cout << "Test case main menu start Failed!" << std::endl;
			window.close();
		}

		result = main.Show(this->window);
	} while (result != 2 || result != 1);

}

//Tests the main menu exit game button
void TestCases::testMainMenuExit()
{

	MainMenu main;
	MainMenu::MenuRes result = main.Show(this->window); //Gets if you should exit game or start game
	do
	{
		if (result == 2) //play game
		{
			std::cout << "Test case main menu exit Failed!" << std::endl;
			window.close();
		}
		else
		{
			std::cout << "Test case main menu exit Successful!" << std::endl;
			window.close();
		}

		result = main.Show(this->window);
	} while (result != 2 || result != 1);
	
}

//Tests dying to Goombas
void TestCases::testDeathByGoomba()
{
	bool gameOver = false;
	while (this->window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Checks collision for mario
		this->checkAllCollision();
		this->checkGroundCollision();

		//Variables for telling if game is over
	

		if (this->checkEnemyCollision()) //Ends Game is mario collides with enemy
		{
			gameOver = true;

			std::cout << "Test case death by Goomba Successful!" << std::endl;
			window.close();
		}
		else
		{
			this->updateGoombas(); //Update goombas
			this->render(); //Draw everything
		}
		this->window.display();
	}
	if (!window.isOpen() && gameOver == false)
		std::cout << "Test case death by Goomba Failed!" << std::endl;
}

//Tests dying by falling off the map
void TestCases::testDeathByFall()
{
	mario->SetPosition(9100, 400);
	bool gameOver = false;
	while (this->window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Checks collision for mario
		this->checkAllCollision();
		this->checkGroundCollision();

		if (mario->getPosition().y > 1000) //If mario falls to death ends game
		{
			gameOver = true;

			std::cout << "Test case death by Fall Successful!" << std::endl;

			window.close();
		}
		else
		{
			this->updateMario();
			this->render(); //Draw everything
		}
		this->window.display();
	}
	if (!window.isOpen() && gameOver == false)
		std::cout << "Test case death by Fall Failed!" << std::endl;
}

//Tests winning the game
void TestCases::testWinGame()
{
	//Creates a message for winning the game
	MyFont.loadFromFile("MyFont.ttf");

	sf::Text text;
	text.setFont(MyFont);
	text.setString("congratulations you win!");
	text.setCharacterSize(165);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(11100, 20));

	sf::Vector2f velocity(sf::Vector2f(0.f, 0.f));

	mario->SetPosition(11000, 400);

	bool gameOver = false;
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
				
		this->updateMario(); //Update mario

		this->render(); //Draw everything

		if (mario->getCharSprite().getPosition().x > 11900) //If mario is at castle, Print text
		{
			window.draw(text);
			gameOver = true;
		}

		window.display();
	}
	if (!window.isOpen() && gameOver == false)
		std::cout << "Test case Win the game Failed!" << std::endl;
	else if (!window.isOpen() && gameOver == true)
		std::cout << "Test case Win the game Successful!" << std::endl;
}