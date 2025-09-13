#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum button_pressed{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
private:
	short unsigned buttonstate;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color textidlecolor;
	sf::Color texthovercolor;
	sf::Color textactivecolor;

	//color
	sf::Color idealcolor;
	sf::Color hovercolor;
	sf::Color activecolor;
public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color ideal_color,sf::Color hover_color, sf::Color active_color);
	~Button();
	//Accessors

	const bool isPressed() const;

	//Functions
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);

};

#endif

