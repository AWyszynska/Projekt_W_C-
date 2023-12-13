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
    sf::Font font; 
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

    sf::Texture obraz1;
    sf::Texture obraz2;
    sf::Texture obraz3;

sf::Text text;
 std::vector<char> ReadSigns;
  char Signs;
   std::vector<int> Readvalues;
  int valuess;
    int xPos;



    void switchToGarden();
    void switchToShop();
    void handleEvents();
    void loadedplace();
    void render();
    void renderTopasek();
    void addToPasek();
};

