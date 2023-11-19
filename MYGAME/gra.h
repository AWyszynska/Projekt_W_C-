#pragma once
#include "guzik.h"
#include <SFML/Graphics.hpp>
#include "garden.h"
#include "shop.h"
#include <vector> 
#include <fstream>

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
    sf::Texture pasek_zdj;
    sf::Sprite pasek;
    bool isRunning;
    sf::Sprite background;
    int zlotowkiValue = 0;
    sf::Font font; // Load your font if not already loaded
    sf::Text zlotowkiText;

    sf::Texture skrzynkazdj;
    sf::Sprite skrzynka;
    std::ifstream zlotowkiFile;
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

