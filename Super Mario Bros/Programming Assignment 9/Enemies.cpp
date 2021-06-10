#include "Enemies.h"


Enemies::Enemies()
{
	initAnimation(); //Initializes animations
}

Enemies::~Enemies()
{

}

void Enemies::initAnimation() //Sets base values
{
	this->animationState = IDLE;
	this->animationTimer.restart();
	this->animationSwitch = true;
}