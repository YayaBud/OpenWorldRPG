#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"

class EditorState :
    public State
{
private:
    //Variables
    sf::Font font;

    std::map<std::string, Button*> buttons;

    //functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~EditorState();

    //FUNCTIONS

    void updateInput(const float& dt)override;
    void updateButtons();
    void update(const float& dt)override;
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr) override;

};
#endif
