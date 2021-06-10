#include "Goomba.h"

Goombas::Goombas() //Calls initializer functions
{
	this->initTexture();
	this->initSprite();
	this->initAnimation();
}

Goombas::Goombas(sf::Vector2f position) //Calls Initializer functions and sets position to included value
{
	this->initTexture();
	this->initSprite();
	this->initAnimation();
	this->goombaSprite.setPosition(position);
}
Goombas::~Goombas()
{

}

void Goombas::initTexture() //Loads texture from file
{
	this->goombaTexture.loadFromFile("Textures/Goomba Sheet.png");
}

void Goombas::initSprite() //Sets sprite to loaded texture
{
	this->goombaSprite.setTexture(this->goombaTexture);
	this->goombaSprite.setTextureRect(sf::IntRect(0, 0, 54, 57));
	this->goombaSprite.setPosition(0,0);
}

void Goombas::initAnimation() //Sets base values for variables
{
	this->animationState = MOVING_LEFT;
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Goombas::renderGoombas(sf::RenderTarget& target) //Draws Goomba to window
{
	target.draw(this->goombaSprite);
}

void Goombas::updateAnimations() //Gives goomba animation
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= .2f || this->getAnimationSwitch())
	{
		this->currentFrame = goombaSprite.getTextureRect();
		if (this->currentFrame == sf::IntRect(0, 0, 54, 57)) //If equal to 1st animation 
		{
			this->currentFrame = sf::IntRect(54, 0, 54, 57); //Set equal to 2nd animation
		}
		else if (this->currentFrame == sf::IntRect(54, 0, 54, 57))//If equal to 2nd animation
		{
			this->currentFrame = sf::IntRect(0, 0, 54, 57); //set to intRect of first animation
		}
		this->animationTimer.restart();
		this->goombaSprite.setTextureRect(currentFrame); //Set animation equal to the new animation
	}
}

void Goombas::movement() //Change goomba position depending on direction they're facing
{
	if (animationState == MOVING_LEFT)
	{
		goombaSprite.setPosition(goombaSprite.getPosition().x - 1, this->goombaSprite.getPosition().y);
	}
	else if (animationState == MOVING_RIGHT)
	{
		goombaSprite.setPosition(goombaSprite.getPosition().x + 1, this->goombaSprite.getPosition().y);
	}
}

void Goombas::checkGoombaCollision(sf::RectangleShape box) //Check if goombas collide with anything
{
	if (this->goombaSprite.getGlobalBounds().intersects(box.getGlobalBounds())) //If Goomba collides with something
	{
		if (this->goombaSprite.getPosition().x - 5 > box.getPosition().x + box.getSize().x / 2) //If walks into right side of an object
		{
			this->animationState = MOVING_RIGHT; //Changes direction
		}
		else if (this->goombaSprite.getPosition().x < box.getPosition().x + box.getSize().x / 2) //Walks into  left side of object
		{
			this->animationState = MOVING_LEFT; //Changes direction
		}
	}
}

bool Goombas::checkGoombaPlayerCollision(sf::Sprite playerSprite, sf::RenderWindow& window) //Checks if goomba and player collide
{
	bool marioDead = false;

	if (animationState == DYING)
	{
		goombaSprite.setPosition(this->goombaSprite.getPosition().x, this->goombaSprite.getPosition().y + 3);
	}
	if (this->goombaSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds())) // if player and goombas hitboxes collide
	{
		if (goombaSprite.getPosition().y - 100 > playerSprite.getPosition().y) //if player is above Goomba, Goombas die
		{
			this->animationState = DYING;
			this->currentFrame = sf::IntRect(108, 0, 54, 57);
			this->goombaSprite.setTextureRect(currentFrame);
		}
		else if (animationState != DYING) //Player is not above Goomba, player dies
		{
			//Close Game. Mario dead
			marioDead = true;
		}
	}

	return marioDead; //Returns if mario is dead
}

const bool& Goombas::getAnimationSwitch() //Smoothens animations
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return animationSwitch;
}

void Goombas::resetAnimationTimer() //Restarts timer
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

