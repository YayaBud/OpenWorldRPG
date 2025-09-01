#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color ideal_color, sf::Color hover_color, sf::Color active_color)
{
	this->buttonstate = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(ideal_color);
	
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(character_size);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->textidlecolor = text_idle_color;
	this->texthovercolor = text_hover_color;
	this->textactivecolor = text_active_color;

	this->idealcolor = ideal_color;
	this->activecolor = active_color;
	this->hovercolor = hover_color;

}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (buttonstate == BTN_ACTIVE)
		return true;


	return false;
}



void Button::update(const sf::Vector2f mousePos)
{
	this->buttonstate = BTN_IDLE;
	/*boolean for hover or pressed*/

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonstate = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonstate = BTN_ACTIVE;
		}
	}

	switch (this->buttonstate)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idealcolor);
		this->text.setFillColor(this->textidlecolor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hovercolor);
		this->text.setFillColor(this->texthovercolor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activecolor);
		this->text.setFillColor(this->textactivecolor);	
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
