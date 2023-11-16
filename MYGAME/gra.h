#pragma once
#include "guzik.h"
#include <SFML/Graphics.hpp>
#include "garden.h"
#include "shop.h"

class Game {
public:
    Game(sf::RenderWindow& window);

    void run();

private:
 sf::RenderWindow& window;
    Guzik ogrod;
    Guzik sad; 
    Guzik kopalnia;   
    Guzik hodowla;
    Guzik sklep;


    bool isRunning;
    sf::Sprite background;

    sf::Texture backgroundTexture;
    sf::Vector2i clickPosition;

    sf::Texture guzikTexture;
    sf::Texture sadzdjecie;
    sf::Texture cavephoto;
    sf::Texture animalphoto;
    sf::Texture shopphoto;


void switchToGarden();
void switchToShop();

    void handleEvents();
    void loadedplace();
    void render();
};

