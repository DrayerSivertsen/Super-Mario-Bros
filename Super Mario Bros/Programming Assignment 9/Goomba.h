#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemies.h"



class Goombas : public Enemies //Inherits from base class Enemies
{
public:
	Goombas(); //Creates goomba and sets them to default position
	Goombas(sf::Vector2f position); //Constuctor that lets you set goomba position
	~Goombas();

	void renderGoombas(sf::RenderTarget& target); //Draws the goombas

	void movement(); //Updates Goomba movement
	void updateAnimations(); //Updates Goomba animations

	//Getter
	const bool& getAnimationSwitch();

	void resetAnimationTimer();	//Resets Timer

	//Collision
	void checkGoombaCollision(sf::RectangleShape box);
	bool checkGoombaPlayerCollision(sf::Sprite playerSprite, sf::RenderWindow& window);
private:
	//Sprites
	sf::Sprite goombaSprite;
	sf::Texture goombaTexture;

	// Animation
	sf::IntRect currentFrame;
	sf::Clock animationTimer;

	//Smoothens Animations
	short animationState;
	bool animationSwitch;

	// Core
	void initTexture();
	void initSprite();
	void initAnimation();


};