#include "Character.h"

Character::Character() //calls all initializers
{
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Character::~Character()
{

}

//functions

const sf::Vector2f Character::getPosition() const //Returns position
{
	return this->Charactersprite.getPosition();
}

void Character::checkPlayerCollision(sf::RectangleShape box)
{
	if (this->Charactersprite.getGlobalBounds().intersects(box.getGlobalBounds()))
	{
		float deltaX = std::abs(Charactersprite.getGlobalBounds().left + (this->Charactersprite.getGlobalBounds().width / 2) - (box.getGlobalBounds().left + box.getGlobalBounds().width / 2));
		float deltaY = std::abs(Charactersprite.getGlobalBounds().top + (this->Charactersprite.getGlobalBounds().height / 2) - (box.getGlobalBounds().top + box.getGlobalBounds().height / 2));
		if (deltaY > deltaX)
		{
			if (this->Charactersprite.getPosition().y + Charactersprite.getGlobalBounds().height > box.getPosition().y + box.getGlobalBounds().height) //If Mario is above the box and collides with box, set posistion to top of box
			{
				this->Charactersprite.setPosition(Charactersprite.getPosition().x, box.getPosition().y + box.getSize().y);

			}
			else if (this->Charactersprite.getPosition().y > box.getGlobalBounds().height - box.getSize().y / 2) //If Mario is Below the box and collides with box, set posistion to top of box
			{
				this->Charactersprite.setPosition(Charactersprite.getPosition().x, box.getPosition().y - Charactersprite.getLocalBounds().height + 10);
			}
		}
		else
		{
			//if to the Right of object, and hitboxes intersect inside of object, teleport to right side of object
			if (this->Charactersprite.getPosition().x + (this->Charactersprite.getGlobalBounds().width / 2) > box.getPosition().x + (box.getSize().x / 2))
			{
				animationState = MOVING_LEFT;
				this->Charactersprite.setPosition(box.getPosition().x + (box.getSize().x), Charactersprite.getPosition().y);
			}
			else //Left
			{
				animationState = MOVING_RIGHT;
				this->Charactersprite.setPosition(box.getGlobalBounds().left - (box.getSize().x / 2) - 14, Charactersprite.getPosition().y);
			}
		}
	}
	if (this->Charactersprite.getPosition().x < 0) //Cant go off map
		this->Charactersprite.setPosition(0, this->Charactersprite.getPosition().y);
	if (this->Charactersprite.getPosition().x >= 12240) {//Cant go off map 
		this->Charactersprite.setPosition(12240, this->Charactersprite.getPosition().y);
		//Go into Winning screen. 
	}
}

bool Character::checkGroundCollision(sf::RectangleShape ground) //Checks sprite's collision with ground
{
	bool collision = false;

	if (this->Charactersprite.getGlobalBounds().intersects(ground.getGlobalBounds()))
	{
		this->Charactersprite.setPosition(this->getPosition().x, ground.getPosition().y - this->Charactersprite.getGlobalBounds().height + 10);
		collision = true;
	}

	return collision;
}

void Character::updateCharacter(sf::RenderTarget& target) //Updates player
{
	this->updateMovement(target);
	this->updateAnimations();
}

void Character::renderChar(sf::RenderTarget& target) //Draws player
{
	target.draw(this->Charactersprite);
}

void Character::initTexture() //Loads player textures from file
{
	this->Charactertexture.loadFromFile("Textures/spritesheet.png");
}

void Character::initFont() //Loads font from file
{
	MyFont.loadFromFile("MyFont.ttf");
}

void Character::initSprite() //Creates player texture
{
	this->Charactersprite.setTexture(this->Charactertexture);
	this->Charactersprite.setTextureRect(sf::IntRect(130, 0, 70, 140)); //sets playerTexture to idle animation

	this->Charactersprite.setPosition(0, 685); //Set starting position of player
}

void Character::initAnimations() //sets player animation variables to starting values
{
	this->animationState = IDLE;
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Character::updateMovement(sf::RenderTarget& target) //Updates player movement depending of W, A, S, or D
{

	//Declaring Physics and camera
	sf::View view;
	sf::Vector2i screenDimensions(1600, 900);
	sf::Vector2f velocity(0.f, 0.f);
	sf::Vector2f position(0, 0);

	//Camera follows player
	view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	if (this->Charactersprite.getPosition().x < 11800)
	{
		position.x = this->Charactersprite.getPosition().x + 30 - (screenDimensions.x / 2);
	}
	if (this->Charactersprite.getPosition().x > 11800) //If player is past flag print Win text
	{
		animationState = IDLE;
		position.x = 11000 + 30;
	}
	if (position.x < 0) //If camera would be off screen, sets camera to default
	{
		position.x = 0;
	}

	//Camera follows mario
	view.reset(sf::FloatRect(position.x, position.y, screenDimensions.x, screenDimensions.y));
	target.setView(view);

	if (animationState2 == WINNING) //Sets different animation states and velocitys if player has won
	{
		if (this->Charactersprite.getPosition().x > 11950)
		{
			velocity.x = 7.0;
			animationState = MOVING_RIGHT;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x = 7.0;
			animationState = MOVING_RIGHT;

		}

		if (!this->checkAllGroundCollision())
		{
			velocity.y += gravity;
		}
	}
	else //Sets animation states and velocity if player has not won
	{
		animationState = IDLE;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Player moves left if A is pressed
		{
			velocity.x = -7.0;
			animationState = MOVING_LEFT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Player moves right if D is pressed
		{
			velocity.x = 7.0;
			animationState = MOVING_RIGHT;

		}
		//Jumping Physics
		bool inAir = false;
		bool canJump = false;
		sf::Time time1 = sf::seconds(0.1);
		sf::Time time2 = sf::seconds(0.3);
		sf::Time time3 = sf::seconds(0.5);

		sf::Time timeCheck1 = sf::seconds(0);
		sf::Time timeCheck2 = sf::seconds(1.2);

		//Timer to tell if player can jump again
		if (timeInAir.getElapsedTime().asSeconds() > timeCheck1.asSeconds() && timeInAir.getElapsedTime().asSeconds() < timeCheck2.asSeconds())
		{
			inAir = true;
		}
		else
		{
			inAir = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && timeInAir.getElapsedTime().asSeconds() > timeCheck2.asSeconds())
		{
			this->timeInAir.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || inAir)
		{
			if (timeInAir.getElapsedTime().asSeconds() < time3.asSeconds())
			{
				if (timeInAir.getElapsedTime().asSeconds() < time1.asSeconds())
				{
					velocity.y = -jumpSpeed;

				}
				else if (timeInAir.getElapsedTime().asSeconds() < time2.asSeconds())
				{
					velocity.y = -21;

				}
				else
				{
					velocity.y = -17;
				}

			}


			animationState = JUMPING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Player crouches if S is pressed
		{
			animationState = CROUCHING;
		}

		if (!this->checkAllGroundCollision())
		{
			velocity.y += gravity;
		}
	}

	

	//Moves Character according to velocity determined above
	this->Charactersprite.move(velocity.x, velocity.y);
}

bool Character::checkAllGroundCollision() //Returns true if any of the grounds are colliding with the player
{
	bool collision = false;

	if (this->checkGroundCollision(this->ground1))
	{
		collision = true;
	}
	else if (this->checkGroundCollision(this->ground2))
	{
		collision = true;
	}
	else if (this->checkGroundCollision(this->ground3))
	{
		collision = true;
	}
	else if (this->checkGroundCollision(this->ground4))
	{
		collision = true;
	}
	return collision;

}

void Character::updateAnimations() //Changes Animations depending on what the player is doing
{
	if (animationState == WINNING)
	{
		//Do nothing
	}
	else if (animationState == IDLE) //Idle animation
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.03f || this->getAnimationSwitch())
		{
			this->currentFrame = sf::IntRect(130, 0, 70, 140); //130, 0, 70, 140 <---IDLE ANIMATION
			this->animationTimer.restart();
			this->Charactersprite.setTextureRect(this->currentFrame);
		}
	}
	else if (animationState == MOVING_RIGHT) //IF JUMPING. GO TO FIRST FRAME, IF WINNING GO TO FIRST FRAME, IF CROUCHING GO TO FIRST FRAME
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimationSwitch()) {
			if (currentFrame == sf::IntRect(130, 0, 70, 140) || currentFrame == sf::IntRect(265, 0, 70, 140) || currentFrame == sf::IntRect(332, 0, 70, 140) || currentFrame == sf::IntRect(402, 0, 70, 140)) //If Idle frame, Go to 1st running animation
				this->currentFrame = sf::IntRect(0, 0, 58, 140);
			else if (currentFrame == sf::IntRect(0, 0, 58, 140)) //If 1st run frame, go to 2nd running animation
				this->currentFrame = sf::IntRect(64, 0, 68, 140);
			else if (currentFrame == sf::IntRect(64, 0, 68, 140)) //If 2nd run frame, to go 3rd running animation
				this->currentFrame = sf::IntRect(201, 0, 60, 140);
			else if (currentFrame == sf::IntRect(201, 0, 60, 140)) //If 3nd run frame, to go 1st running animation
				this->currentFrame = sf::IntRect(0, 0, 58, 140);
			this->animationTimer.restart();
			this->Charactersprite.setTextureRect(this->currentFrame);
			this->Charactersprite.setScale(1.0f, 1.0f); //Set player to normal direction
			this->Charactersprite.setOrigin(0.f, 0.f);
		}
	}
	else if (animationState == MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimationSwitch()) {
			if (currentFrame == sf::IntRect(130, 0, 70, 140) || currentFrame == sf::IntRect(265, 0, 70, 140) || currentFrame == sf::IntRect(332, 0, 70, 140) || currentFrame == sf::IntRect(402, 0, 70, 140)) //If Idle frame, Go to 1st running animation
				this->currentFrame = sf::IntRect(0, 0, 58, 140);
			else if (currentFrame == sf::IntRect(0, 0, 58, 140)) //If 1st run frame, go to 2nd running animation
				this->currentFrame = sf::IntRect(64, 0, 68, 140);
			else if (currentFrame == sf::IntRect(64, 0, 68, 140)) //If 2nd run frame, to go 3rd running animation
				this->currentFrame = sf::IntRect(201, 0, 60, 140);
			else if (currentFrame == sf::IntRect(201, 0, 60, 140)) //If 3nd run frame, to go 1st running animation
				this->currentFrame = sf::IntRect(0, 0, 58, 140);
			this->animationTimer.restart();
			this->Charactersprite.setTextureRect(this->currentFrame);
			this->Charactersprite.setScale(-1.f, 1.f); //Invert player
			this->Charactersprite.setOrigin(this->Charactersprite.getGlobalBounds().width / 1.f, 0.f);
		}
	}
	else if (animationState == JUMPING)
	{
		this->currentFrame = sf::IntRect(265, 0, 70, 140); //Jumping animation
		this->animationTimer.restart();
		this->Charactersprite.setTextureRect(this->currentFrame);

	}
	else if (animationState == CROUCHING)
	{
		this->currentFrame = sf::IntRect(332, 0, 70, 140); //Crouching animation
		this->animationTimer.restart();
		this->Charactersprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}

//Creates smoother animation
const bool& Character::getAnimationSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return animationSwitch;
}

//Restarts time and switches animations
void Character::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

//Returns character sprite
sf::Sprite Character::getCharSprite()
{
	return this->Charactersprite;
}

//Checks if player collides with flagpole
void Character::checkFlagPoleCollision(sf::RectangleShape Flag)
{
	if (Flag.getGlobalBounds().intersects(this->Charactersprite.getGlobalBounds()))
	{
		animationState2 = WINNING; //Player has won, changes how game runs
		animationState = WINNING; //Player has won, changes how game runs
		if (this->Charactersprite.getPosition().y + Charactersprite.getLocalBounds().height >= 723) //If player is above flagpost block, player is on left side of pole
		{
			currentFrame = sf::IntRect(402, 0, 70, 140);
			this->Charactersprite.setTextureRect(currentFrame);
			this->Charactersprite.setPosition(this->Charactersprite.getPosition().x + 5, this->Charactersprite.getPosition().y - 3);
			this->Charactersprite.setScale(-1.f, 1.f);
			this->Charactersprite.setOrigin(this->Charactersprite.getGlobalBounds().width / 1.f, 0.f);
		}
		else //If player is below flagpost block, player is on right side of pole
		{
			currentFrame = sf::IntRect(402, 0, 70, 140);
			this->Charactersprite.setTextureRect(currentFrame);
			this->Charactersprite.setPosition(this->Charactersprite.getPosition().x, this->Charactersprite.getPosition().y - 3);
			this->Charactersprite.setScale(1.f, 1.f);
			this->Charactersprite.setOrigin(0.f, 0.f);
			  
			

		}
	}
}

void Character::SetPosition(float x, float y)
{
	this->Charactersprite.setPosition(x, y);
}