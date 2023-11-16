#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "guziksklep.h"
#include <vector>
#include <sstream>

class Shop {

public:
    Shop(sf::RenderWindow& window); 
        std::ostringstream ss;
    void run();

private:
    static const size_t maxZbiornikSize = 100;
    Guziksklep buykernel1;
    Guziksklep buykernel2;
    Guziksklep buykernel3;

 sf::RenderWindow& window;
    sf::Sprite background;
    sf::Texture backgroundTexture;

    bool isPszenicaPressed;

    char marchewkaznak = 'M';
    char pszenicaznak = 'P';
    char truskawkaznak = 'T';

    int licznik = 0;

    sf::Texture pricesset1;
    sf::Texture pricesset2;
    sf::Texture pricesset3;
    sf::Sprite price1;
    sf::Sprite price2;
    sf::Sprite price3;

    int liczba = 42;

    sf::Texture ziar1;
    sf::Texture ziar2;
    sf::Texture ziar3;

    sf::Texture pasek_zdj;
    sf::Sprite pasek;

    std::vector<char> zbiornik;
    std::vector<char> wypisz;
    std::vector<int> letter= {0,0,0,0};
   // auto it;
    bool found;

sf::Font font;
sf::Text text;
int xPos;

    int zlotowki = 10000;
    sf::Text pieniadze;

    sf::Texture obraz1;
    sf::Texture obraz2;
sf::Texture obraz3;

    sf::Texture skrzynkazdj;
    sf::Sprite skrzynka;
 std::string zlotowkiStr;
    bool isRunning;
    void render();
    void handleEvents();
    void addprice();
    void addkernalforshelf();
    void tableforunder();
    void drawValuesAtBottom(); 
    void zlicz();
};
