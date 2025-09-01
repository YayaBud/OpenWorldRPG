#include "Entity.h"

void Entity::initVariables()
{
	this->hitboxComponent = NULL;
	this->movementComponenet = NULL;
	this->animationComponent = NULL;
}

Entity::Entity()
{
	this->initVariables();	
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movementComponenet;
	delete this->animationComponent;	
}


//Component functions

void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createHitboxComponent(sf::Sprite& sprite,
	float offset_x, float offset_y,
	float height, float width)
{
	this->hitboxComponent = new HitboxComponent(sprite,offset_x,offset_y,width,height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponenet = new MovementComponent(this->sprite, maxVelocity,acceleration,deceleration);
}

void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, textureSheet);
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
}

void Entity::render(sf::RenderTarget& target)
{

	target.draw(this->sprite);

	if(this->hitboxComponent)
		this->hitboxComponent->render(target);

}
