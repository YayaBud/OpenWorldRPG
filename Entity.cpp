#include "Entity.h"

void Entity::initVariables()
{
	this->movementComponenet = NULL;
}

Entity::Entity()
{
	this->initVariables();	
}

Entity::~Entity()
{
	delete this->movementComponenet;
	delete this->animationComponent;	
}


//Component functions

void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponenet = new MovementComponent(this->sprite, maxVelocity,acceleration,deceleration);
}

void Entity::createAnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
{
	this->animationComponent = new AnimationComponent(sprite, textureSheet);
}

//functions 

void Entity::setPosition(const float x, float y)
{

	this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y,const float& dt)
{	
	if (this->movementComponenet)
	{
		this->movementComponenet->move(dir_x, dir_y, dt);
	}
}

void Entity::update(const float& dt)
{
	if (this->movementComponenet)
		this->movementComponenet->update(dt);
}

void Entity::render(sf::RenderTarget* target)
{

	target->draw(this->sprite);

}
