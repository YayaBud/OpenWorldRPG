#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
    public Entity
{
private:
    //variables
	bool attacking;
    
    //init functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

	//functions
	void updateAttack();
	void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif 
