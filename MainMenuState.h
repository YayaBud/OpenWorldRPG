#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    //Variables
    sf::Texture BackgroundTexture;
    sf::RectangleShape background;
    sf::Font font; 

    std::map<std::string, Button*> buttons;

    //functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    //FUNCTIONS

    void updateInput(const float& dt)override;
    void updateButtons();
    void update(const float& dt)override;
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr) override;

};
#endif 

