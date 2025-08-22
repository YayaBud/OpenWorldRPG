#include "Player.h"

//initfucntions
void Player::initVariables()
{

}

void Player::initComponents()
{

}


//constructors and destructors
Player::Player(float x,float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setTexture(texture_sheet);
	this->setPosition(x,y);

	this->createMovementComponent(250.f, 10.f, 4.f);
	this->createAnimationComponent(this->sprite, texture_sheet);

	this->animationComponent->addAnimation("IDLE", 100.f, 1, 1, 14, 1, 192, 192);
}

Player::~Player()
{

}
