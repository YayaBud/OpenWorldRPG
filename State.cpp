#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* states)
{
	this->window = window;
	this->supportedKeys = supportedkeys;
	this->states = states;
	this->quit = false;
	this->paused = false;
	this->keytimeMax = 10.f;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}

const bool State::getKeyTime()
{
	if (this->keytime >= keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}
	else
		return false;
}

void State::endState()
{
	this->quit = true;
}

void State::pauseState()
{
	this->paused = true;
}

void State::unpauseState()
{
	this->paused = false;
}

void State::UpdateMousePositions()
{
	this->MousePosScreen = sf::Mouse::getPosition();
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->MousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}

void State::updateKeyTime(const float& dt)
{
	if (this->keytime < keytimeMax)
		this->keytime += 100.f * dt;
}


