#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& spirit,
	float maxVelocity,float acceleration,float deceleration)
	: sprite(spirit), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->Velocity;
}

//functions

const bool MovementComponent::getState(const short unsigned state) const
{
    switch (state)
    {
    case IDLE:
        if (this->Velocity.x == 0.f && this->Velocity.y == 0.f)
            return true;
        break;
	case MOVING:
        if(this->Velocity.x != 0.f || this->Velocity.y != 0.f)
            return true;
        break;
    case MOVING_LEFT:
        if (this->Velocity.x < 0.f)
            return true;
        break;
	case MOVING_RIGHT:
        if (this->Velocity.x > 0.f)
            return true;
        break;
	case MOVING_UP:
        if (this->Velocity.y < 0.f)
            return true;
        break;
    case MOVING_DOWN:
        if (this->Velocity.y > 0.f)
            return true;
        break;
    }
    
    return false;
}

void MovementComponent::move(const float dir_x, const float dir_y,const float& dt)
{
	//Acceleration
	this->Velocity.x += this->acceleration * dir_x;
	this->Velocity.y += this->acceleration * dir_y;
	
}

void MovementComponent::update(const float& dt)
{
    // X direction
    if (this->Velocity.x > 0.0f) // moving right
    {
        if (this->Velocity.x > this->maxVelocity)
            this->Velocity.x = this->maxVelocity;

        this->Velocity.x -= deceleration;
        if (this->Velocity.x < 0.0f)
            this->Velocity.x = 0.0f;
    }
    else if (this->Velocity.x < 0.0f) // moving left
    {
        if (this->Velocity.x < -this->maxVelocity)
            this->Velocity.x = -this->maxVelocity;

        this->Velocity.x += deceleration;
        if (this->Velocity.x > 0.0f)
            this->Velocity.x = 0.0f;
    }

    // Y direction
    if (this->Velocity.y > 0.0f) // moving down
    {
        if (this->Velocity.y > this->maxVelocity)
            this->Velocity.y = this->maxVelocity;

        this->Velocity.y -= deceleration;
        if (this->Velocity.y < 0.0f)
            this->Velocity.y = 0.0f;
    }
    else if (this->Velocity.y < 0.0f) // moving up
    {
        if (this->Velocity.y < -this->maxVelocity)
            this->Velocity.y = -this->maxVelocity;

        this->Velocity.y += deceleration;
        if (this->Velocity.y > 0.0f)
            this->Velocity.y = 0.0f;
    }

	//velocity
	this->sprite.move(this->getVelocity() * dt);
}
