#include "Game.h"

//static functions 

//init function
void Game::initWindow()
{
    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
    /*this->supportedKeys.emplace("ESC", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
    */

    std::ifstream ifs("Config/supported_Keys.ini");

    if (ifs.is_open())
    {

        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();
    /*this->supportedKeys["ESCAPE"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    */
    
    //DEBUG
    
    for(const auto &i :this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    //std::cout << this->supportedKeys.at("A") << std::endl;
}

void Game::initStates()
{
    this->states.push(new GameState(this->window,&this->supportedKeys)); 
}


//Constructors & Destructors
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//functions

void Game::endApplication()
{
    std::cout << "ending application " << std::endl;
}

void Game::updateDt()
{
    //updates the dt variable with the time it takes to updates and render one frame.

    this->dt = this->dtclock.restart().asSeconds();
  
}

void Game::updateSFMLEvents()
{
    
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}
	
void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
        //Application End 
    }
    else
    {
        this->endApplication();
        this->window->close(); 
    }
    
}

void Game::render()
{
    window->clear();

    //render items
    if (!this->states.empty())
        this->states.top()->render(this->window);

    window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

