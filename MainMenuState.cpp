#include "MainMenuState.h"
#include "GameState.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("MainMenuState::initFonts failed to load :[ ");
	}
}

void MainMenuState::initKeybinds()
{

	std::ifstream ifs("Config/GameState_Keybinds.ini");

	if (ifs.is_open())
	{

		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();

}

void MainMenuState::initButtons()
{

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	/*this->gamestate_btn = new Button(100, 100, 150, 50,
		&this->font,"New Game",
		sf::Color(70,70,70,200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));*/

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{	
	auto it = this->buttons.begin();
	for (it = this->buttons.begin();it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	std::cout << "end" << std::endl;
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))

}

void MainMenuState::update(const float& dt)
{
	this->UpdateMousePositions();
	this->updateInput(dt);
	
	//this->gamestate_btn->update(this->MousePosView);
	
	
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);

	//this->gamestate_btn->render(target);
}
