#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "pauseMenu.h"


class GameState :
    public State
{
private:
    Player *player;
    sf::Font font;
	PauseMenu* pmenu;   

    //functions
    void initKeybinds();
    void initTexture();
    void initPlayers();
    void initPauseMenu();
    void initFonts();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //FUNCTIONS


	void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();
    void update(const float& dt)override;
    void render(sf::RenderTarget* target = nullptr) override;

};
#endif 

    