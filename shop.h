#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "guziksklep.h"
#include "guzik.h"
#include <vector>
#include <sstream>
#include "gra.h"
#include <fstream>

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
    Guziksklep buykernel4;
    Guziksklep buykernel5;
    Guziksklep buykernel6;

 sf::RenderWindow& window;
    sf::Sprite background;
    sf::Texture backgroundTexture;

    bool isPszenicaPressed;

    char marchewkaznak = 'M';
    char pszenicaznak = 'P';
    char truskawkaznak = 'T';
    char jablkoznak = 'J';
    char gruszkaznak = 'G';
    char sliwkaznak = 'Z';

    int licznik = 0;

    sf::Texture pricesset1;
    sf::Texture pricesset2;
    sf::Texture pricesset3;
    sf::Texture pricesset4;
    sf::Texture pricesset5;
    sf::Texture pricesset6;
    sf::Sprite price1;
    sf::Sprite price2;
    sf::Sprite price3;
    sf::Sprite price4;
    sf::Sprite price5;
    sf::Sprite price6;

    int liczba = 42;


    Guzik exit;
    sf::Texture exittextur;

    sf::Texture ziar1;
    sf::Texture ziar2;
    sf::Texture ziar3;
    sf::Texture ziar4;
    sf::Texture ziar5;
    sf::Texture ziar6;

    sf::Texture pasek_zdj;
    sf::Sprite pasek;

    std::vector<char> zbiornik;
    std::vector<char> wypisz;
    std::vector<int> letter= {0,0,0,0};

    bool found;

sf::Font font;
sf::Text text;
int xPos;

    int zlotowki = 10000;
    sf::Text pieniadze;

    sf::Texture obraz1;
    sf::Texture obraz2;
    sf::Texture obraz3;
    sf::Texture obraz4;
    sf::Texture obraz5;
    sf::Texture obraz6;

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
    void switchTofarm();
};