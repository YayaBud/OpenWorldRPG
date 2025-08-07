#include "Player.h"

//initfucntions
void Player::initVariables()
{

}

void Player::initComponents()
{
	
}


//constructors and destructors
Player::Player(float x,float y, sf::Texture* texture)
{
	this->initComponents();
	this->initVariables();

	this->createSprite(texture);
	this->setPosition(x,y);
}

Player::~Player()
{

}
