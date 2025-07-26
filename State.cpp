#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys)
{
	this->window = window;
	this->supportedKeys = supportedkeys;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ESCAPE"))))
	{
		this->quit = true;
	}

}


