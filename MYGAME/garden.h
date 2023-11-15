#pragma once
#include "guzikwarz.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

class Garden {

public:
    Garden(sf::RenderWindow& window); 
    void handleSadzonkaInteraction();
    void changeImage();
    void run();

private:


 sf::RenderWindow& window;
    sf::Clock timer;
    bool isSadzonkaPressed;
    bool isRunning;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    int currentImage;
    GuzikWarzywa sadzonka;
    sf::Texture ziarno1;
    bool isThirdImageDisplayed;

    sf::Texture pasek;
    sf::Texture kopiec;
    sf::Texture pszenica;

    sf::Sprite pszenica2;
    sf::Sprite pasek2;
    sf::Sprite dokopiec;
    sf::Sprite dokopiec2;
    sf::Sprite dokopiec3;
    sf::Sprite dokopiec4;
    sf::Vector2f position;
    
    void handleEvents();
    void render();
    void kopcephoto();
};
