#include "GameState.h"

//init functions
void GameState::initKeybinds()
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



	/*this->keybinds["ESCAPE"] = this->supportedKeys->at("ESCAPE");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	*/
}

void GameState::initTexture()
{
	sf::Texture temp;
	temp.loadFromFile("Resources/Images/Sprites/Player/test.png");
	this->textures["PLAYER_IDLE"] = temp;
}
void GameState::initPlayers()
{
	this->player = new Player(0, 0, this->textures["PLAYER_IDLE"]);
}

//const and destu

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window ,supportedKeys,states)
{
	this->initKeybinds();
	this->initTexture();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}


void GameState::updateInput(const float& dt)
{
	//Update player input 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move( -1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ESCAPE"))))
		this->endState();
		
}

void GameState::update(const float& dt)
{
	this->UpdateMousePositions();
	this->updateInput(dt);
	this->player->update(dt);
}	

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->player->render(this->window);
}
	