#include "Player.h"

//initfucntions
void Player::initVariables()
{

}

void Player::initComponents()
{
	this->createMovementComponent(250.f,10.f,4.f);
}


//constructors and destructors
Player::Player(float x,float y, sf::Texture& texture)
{
	this->initComponents();
	this->initVariables();

	this->setTexture(texture);
	this->setPosition(x,y);
}

Player::~Player()
{

}
