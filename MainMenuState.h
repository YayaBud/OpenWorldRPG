#ifndef MAINMENU_H
#define MAINMENU_H
#include "State.h"

class MainMenuState :
    public State
{
private:
    Entity player;

    //functions
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    //FUNCTIONS

    void endState()override;

    void updateInput(const float& dt)override;
    void update(const float& dt)override;
    void render(sf::RenderTarget* target = nullptr) override;

};
#endif 

