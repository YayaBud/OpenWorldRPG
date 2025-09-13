#include "Player.h"

//initfucntions
void Player::initVariables()
{
	this->attacking = false;
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

void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		attacking = true;
}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking) {
		//set origin to the middle of the sprite
		if(this->sprite.getScale().x > 0.f)
			this->sprite.setOrigin(96.f, 0.f);
		else
			this->sprite.setOrigin(258.f + 96.f, 0.f);

		if (this->animationComponent->play("ATTACK", dt, true)) {

			this->attacking = false;

			if (this->sprite.getScale().x > 0.f)
				this->sprite.setOrigin(0.f, 0.f);
			else
				this->sprite.setOrigin(258.f, 0.f);

			
		}
	}

	else if (this->movementComponenet->getState(IDLE))
		this->animationComponent->play("IDLE_ANIMATION", dt);

	else if (this->movementComponenet->getState(MOVING_LEFT)) {
		if (this->sprite.getScale().x < 0.f)
		{
			this->sprite.setOrigin(0.f, 0.f);
			this->sprite.setScale(1.f, 1.f);
		}
		this->animationComponent->play("WALK", dt, this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}
	else if (this->movementComponenet->getState(MOVING_RIGHT)) {
		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(258.f, 0.f);
			this->sprite.setScale(-1.f, 1.f);
		}
		this->animationComponent->play("WALK", dt, this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}
	else if (this->movementComponenet->getState(MOVING_UP)) {
		this->animationComponent->play("WALK", dt, this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}
	else if (this->movementComponenet->getState(MOVING_DOWN)) {
		this->animationComponent->play("WALK", dt, this->movementComponenet->getVelocity().x, this->movementComponenet->getMaxVelocity());
	}
}

//functions
void Player::update(const float& dt)
{
	this->movementComponenet->update(dt);

	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}	
