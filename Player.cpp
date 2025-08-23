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

	this->setPosition(x,y);

	this->createMovementComponent(250.f, 10.f, 4.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_ANIMATION", 10.f, 0, 0, 13, 0, 192, 192);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 1, 11, 1, 192, 192);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 1, 11, 1, 192, 192);
}

Player::~Player()
{

}

//functions
void Player::update(const float& dt)
{
	this->movementComponenet->update(dt);

	if (this->movementComponenet->getState(IDLE))
		this->animationComponent->play("IDLE_ANIMATION", dt);
	else if (this->movementComponenet->getState(MOVING_LEFT))
		this->animationComponent->play("WALK_LEFT", dt);
	//else if (this->movementComponenet->movingRight())
		//this->animationComponent->play("WALK_RIGHT", dt);
}
