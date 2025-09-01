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

	this->createHitboxComponent(this->sprite, 86.f, 70.f, 86.f,121.f);
	this->createMovementComponent(250.f, 10.f, 4.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_ANIMATION", 10.f, 0, 0, 13, 0, 192, 192);
	this->animationComponent->addAnimation("WALK",7.f, 0, 1, 11, 1, 192, 192);
	this->animationComponent->addAnimation("ATTACK", 6.f, 0, 2, 13, 2, 192*2, 192);
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
	else if (this->movementComponenet->getState(MOVING_LEFT)) {
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->animationComponent->play("WALK", dt,this->movementComponenet->getVelocity().x,this->movementComponenet->getMaxVelocity());
	}
	else if (this->movementComponenet->getState(MOVING_RIGHT)) {
		this->sprite.setOrigin(258.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent->play("WALK", dt,this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}
	else if (this->movementComponenet->getState(MOVING_UP)) {
		this->animationComponent->play("WALK", dt,this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}
	else if (this->movementComponenet->getState(MOVING_DOWN)) {
		this->animationComponent->play("WALK", dt,this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}

	this->hitboxComponent->update();
}	
