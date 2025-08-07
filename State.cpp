#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* states)
{
	this->window = window;
	this->supportedKeys = supportedkeys;
	this->quit = false;
	this->states = states;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::endState()
{
	this->quit = true;
}



void State::UpdateMousePositions()
{
	this->MousePosScreen = sf::Mouse::getPosition();
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->MousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}


