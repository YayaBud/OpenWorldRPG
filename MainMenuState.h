#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    //Variables
    sf::RectangleShape background;
    sf::Font font; 

    std::map<std::string, Button*> buttons;

    //functions
    void initFonts();
    void initKeybinds();
    void initButtons();

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

