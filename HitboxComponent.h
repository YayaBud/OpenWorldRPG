#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
	
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class HitboxComponent
{
private:
	sf::RectangleShape hitbox;
	sf::Sprite& sprite;
	float offsetX;
	float offsetY;

public:

	HitboxComponent(sf::Sprite& sprite,
		float offset_x,float offset_y,
		float height,float width);

	virtual ~HitboxComponent();

	//functions
	bool checkIntersect(const sf::FloatRect& frect) const;

	void update();
	void render(sf::RenderTarget& target);
};
#endif
