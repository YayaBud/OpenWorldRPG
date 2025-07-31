#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text,
	sf::Color idealcolor, sf::Color hovercolor, sf::Color activecolor)
{
	this->buttonstate = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(24);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idealcolor = idealcolor;
	this->activecolor = activecolor;
	this->hovercolor = hovercolor;

	this->shape.setFillColor(this->idealcolor);

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
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hovercolor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activecolor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
