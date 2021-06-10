#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"


class Enemies //Base class for all enemies to inherit from
{
public:
	Enemies();
	~Enemies();

private:

	//Sprites
	sf::Sprite enemiesSprite;
	sf::Texture enemiesTexture;

	// Animation
	sf::IntRect currentFrame; //Current animation frame
	sf::Clock animationTimer; //Keeps track of how long player has held animation for
	//Smoothens animations
	short animationState;
	bool animationSwitch;

	// Core
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
	virtual void initAnimation();


};