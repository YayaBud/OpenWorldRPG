#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"

class Entity
{
private:

	void initVariables();


protected:
	
	sf::Sprite sprite;
	
	MovementComponent* movementComponenet;

public:
	Entity();
	virtual ~Entity();

	//Component functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocityconst, const float acceleration, const float deceleration);
	
	//functions 

	virtual void setPosition(const float x, float y);
	virtual void move(const float x, const float y, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};
#endif

