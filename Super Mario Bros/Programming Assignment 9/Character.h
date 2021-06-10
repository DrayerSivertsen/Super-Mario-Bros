#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PhysicalProperties.h"
//Global Physics variables
#define gravity 10.0
#define groundHeight 1200
#define jumpSpeed 25.0

//different playerStates for setting animations
enum PlayerState { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, CROUCHING, DYING, WINNING, END}; 

class Character : public PhysicalProps //Inherits the physicalProps class so that we can check collision with the platforms
{
public:
	Character();
	~Character();
	//functions
	void updateCharacter(sf::RenderTarget& target); //Calls updateMovement() and updateAnimations()
	void renderChar(sf::RenderTarget& target); //Renders Mario
	void updateMovement(sf::RenderTarget& target); //Updates Mario's movement
	void updateAnimations(); //Updates Mario's animations
	
	//Used to help smoothen animations
	const bool& getAnimationSwitch();
	void resetAnimationTimer();

	//Getters
	sf::Sprite getCharSprite(); //returns CharacterSprite
	const sf::Vector2f getPosition() const; //returns characterSprite positions

	//Checks collision
	void checkPlayerCollision(sf::RectangleShape box); //Checks playerCollision with 
	bool checkGroundCollision(sf::RectangleShape ground); //Checks collision for 1 collision
	bool checkAllGroundCollision(); //Checks if player is touching ground for updateMovement()
	void checkFlagPoleCollision(sf::RectangleShape Flag); //Checks if player has beat the level

	//Initiates font
	void initFont();

	void SetPosition(float x, float y);

private:
	sf::Sprite Charactersprite;
	sf::Texture Charactertexture;
	sf::Clock timeInAir;
	//Animation
	sf::IntRect currentFrame; //Current animation frame
	sf::Clock animationTimer; //Keeps track of how long player has held animation for

	//Smoothens animations
	short animationState;
	short animationState2;
	bool animationSwitch;

	// Font
	sf::Font MyFont;

	//Core
	void initTexture();
	void initSprite();
	void initAnimations();

};