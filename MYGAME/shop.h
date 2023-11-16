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
    std::ostringstream ss;
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
    std::vector<char> letter;

    bool found;

    sf::Texture obraz1;
    sf::Texture obraz2;
sf::Texture obraz3;
    std::map<char, int> letterCount; // Zliczanie wystąpień liter

    // ... reszta funkcji pozostaje bez zmian
    void updateLetterCount(char letter);
    bool isRunning;
    void render();
    void handleEvents();
    void addprice();
    void addkernalforshelf();
    void tableforunder();
    void drawValuesAtBottom(); 
    void zlicz();
};
