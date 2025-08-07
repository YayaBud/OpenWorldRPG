#ifndef STATE_H
#define STATE_H

#include "Player.h"

class State
{
private:

protected:
	std::stack<State*>* states;

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit ; 

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

	//Resources
	std::map<std::string, sf::Texture>textures;

	//functions
	virtual void initKeybinds() = 0;

public:

	State(sf::RenderWindow* window,std::map<std::string, int>* supportedkeys, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;
	void endState();

	virtual void UpdateMousePositions();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
	
#endif