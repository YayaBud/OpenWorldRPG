#include "SettingsState.h"



void SettingsState::initVariables()
{

}

void SettingsState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->BackgroundTexture.loadFromFile("Resources/Images/Background/bg1.png"))
		throw "Error";

	this->background.setTexture(&this->BackgroundTexture);

}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("MainMenuState::initFonts failed to load :[ ");
	}
}

void SettingsState::initKeybinds()
{

	std::ifstream ifs("Config/mainmenustates_Keybinds.ini");

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

void SettingsState::initButtons()
{
	this->buttons["EXIT_STATE"] = new Button(100, 780, 150, 50,
		&this->font, "Exit", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}
SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window,supportedKeys,states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


//Functions

void SettingsState::updateInput(const float& dt)
{

	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))

}

void SettingsState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->MousePosView);
	}
	//quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
		//this->states.push(new MainMenuState(this->window, &this->supportedKeys));
	}

}

void SettingsState::update(const float& dt)
{
	this->UpdateMousePositions();
	this->updateInput(dt);
	this->updateButtons();



	//this->gamestate_btn->update(this->MousePosView);


}

void SettingsState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);

	this->renderButtons(*target);


}