#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include "garden.h"

class Openall {
public:
    Openall(sf::RenderWindow& window, std::vector<char> charvalues,std::vector<int> intvalues);
    void drawtank();
    void addsToPasek();
    
private:
    sf::RenderWindow& window;
    sf::Texture werehousephoto;
    sf::Sprite werehouse;
    std::vector<char> charvalues;
    std::vector<int> intvalues;
    sf::Texture carrottolinephoto;
sf::Texture strawberrytolinephoto;
sf::Sprite carrottoline;
sf::Sprite strawberrytoline;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;

    sf::Texture obraz1;
    sf::Texture obraz2;
    sf::Texture obraz3;
        int xPos;
        int position;
        sf::Text text;
    

};