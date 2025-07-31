#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtclock;
	float dt; 

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	 
	//Init
	void initWindow();
	void initKeys();
	void initStates();
	
public:
	//Constructors & Destructors
	Game();
	virtual ~Game();

	//functions

	void endApplication();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif


