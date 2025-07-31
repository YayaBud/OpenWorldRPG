#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State
{
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit ; 

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;



	//Resources
	std::vector<sf::Texture> textures;
	//functions
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow* window,std::map<std::string, int>* supportedkeys);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void UpdateMousePositions();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
	
#endif