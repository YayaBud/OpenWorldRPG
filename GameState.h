#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"


class GameState :
    public State
{
private:
    Player *player;

    //functions
    void initKeybinds();
    void initTexture();
    void initPlayers();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //FUNCTIONS



    void updateInput(const float& dt)override;
    void update(const float& dt)override;
    void render(sf::RenderTarget* target = nullptr) override;

};
#endif 

    