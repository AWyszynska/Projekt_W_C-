
#include "shop.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <sstream>

Shop::Shop(sf::RenderWindow& window) : window(window),
    buykernel1(window, sf::Vector2f(200, 210), sf::Vector2f(100, 100)),
    buykernel2(window, sf::Vector2f(356, 210), sf::Vector2f(100, 100)),
    buykernel3(window, sf::Vector2f(512, 210), sf::Vector2f(100, 100)),
    isRunning(true),zlotowki(10000),
    pieniadze(sf::Text("", font, 30)) {
    window.setFramerateLimit(60);



    if (!backgroundTexture.loadFromFile("aazdj/sklepzdj.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    background.setTexture(backgroundTexture);
   




        if (!font.loadFromFile("Flottflott.ttf")) {
            std::cout << "Error loading font file!" << std::endl;
        }
         else{
            std::cout << "działa" << std::endl;
        }
        text.setFont(font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);


        pieniadze.setFont(font);
        pieniadze.setCharacterSize(30);
        pieniadze.setFillColor(sf::Color::Black);

    ss << zlotowki; // Inicjalizacja ss
    zlotowkiStr = ss.str();

}

void Shop::addprice(){
    if (!skrzynkazdj.loadFromFile("aazdj/skrzynka.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    skrzynka.setTexture(skrzynkazdj);
    skrzynka.setPosition(950.0f, 0.0f);
    skrzynka.setScale(0.5f, 0.5f);

    if (!pasek_zdj.loadFromFile("aazdj/pasek.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    pasek.setTexture(pasek_zdj);
    pasek.setPosition(260.0f, 680.0f);
    pasek.setScale(0.9f, 0.9f);

    if (!pricesset1.loadFromFile("aazdj/pszencena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price1.setTexture(pricesset1);
    price1.setPosition(154.0f, 270.0f);
    price1.setScale(0.5f, 0.5f);

    if(!pricesset2.loadFromFile("aazdj/marcena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price2.setTexture(pricesset2);
    price2.setPosition(314.0f, 270.0f);
    price2.setScale(0.5f, 0.5f);

    if(!pricesset3.loadFromFile("aazdj/truskcena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price3.setTexture(pricesset3);
    price3.setPosition(474.0f, 270.0f);
    price3.setScale(0.5f, 0.5f);

}

void Shop::addkernalforshelf(){
    if (!ziar1.loadFromFile("aazdj/nasiono1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    buykernel1.setTexture(ziar1);
    if (!ziar2.loadFromFile("aazdj/nasionamarchewka.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    buykernel2.setTexture(ziar2);
    if (!ziar3.loadFromFile("aazdj/nasionatruskawka.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    buykernel3.setTexture(ziar3);
}


void Shop::run() {
    while (window.isOpen()) {
        handleEvents();
        addprice();
        render();
        addkernalforshelf();

    }
}

void Shop::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            if (buykernel1.isHoveredButton()) {//pszenica
                 zbiornik.push_back(pszenicaznak);
                 licznik = 0; 

        for (char num : zbiornik) {
                         if (num == 'P') {
                            licznik++;
                    }
                    }
            found = false;
            for (char znak : wypisz) {
            if (znak == pszenicaznak) {
                found = true;
                break;
            }
         }

         if (!found) {
        wypisz.push_back(pszenicaznak);
        }

    auto it = std::find(wypisz.begin(), wypisz.end(), 'P');
    if (it != wypisz.end()) {
        int position = std::distance(wypisz.begin(), it);
        letter[position]++;
    } 
            }
            else if (buykernel2.isHoveredButton()) {//marchewka
            
                 zbiornik.push_back(marchewkaznak);
                 licznik = 0;   
                  found = false;
            for (char znak : wypisz) {
            if (znak == marchewkaznak) {
                found = true;
                break;
            }
         }

         if (!found) {
        wypisz.push_back(marchewkaznak);
        }
    auto it = std::find(wypisz.begin(), wypisz.end(), 'M');
    if (it != wypisz.end()) {
        int position = std::distance(wypisz.begin(), it);
        letter[position]++;
    } 
 
            }
            else if (buykernel3.isHoveredButton()) {//truskawka
              
                 zbiornik.push_back(truskawkaznak);
                 licznik = 0; 

            for (char znak : wypisz) {
            if (znak == truskawkaznak) {
                found = true;
                break;
            }
         }

         if (!found) {
        wypisz.push_back(truskawkaznak);
        }
    auto it = std::find(wypisz.begin(), wypisz.end(), 'T');
    if (it != wypisz.end()) {
        int position = std::distance(wypisz.begin(), it);
        letter[position]++;
    } 
      
        }
    }
}
}

void Shop::tableforunder(){

        int position = 270;
    int interval = 150;

    for (char znak : wypisz) {
        if (znak == 'P') {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {
                sf::Sprite sprite(obraz1);
                sprite.setPosition(position,690); 
                sprite.setScale(0.15f, 0.15f);
                window.draw(sprite);
                
            }
        } else if (znak == 'M') {
           
            if (obraz2.loadFromFile("aazdj/nasionamarchewka.png")) {
                sf::Sprite sprite(obraz2);
                sprite.setPosition(position,700); 
                sprite.setScale(0.7f, 0.7f);
                window.draw(sprite);
            }
        } else if (znak == 'T') {

            if (obraz3.loadFromFile("aazdj/nasionatruskawka.png")) {
                sf::Sprite sprite(obraz3);
                sprite.setPosition(position,690); 
                sprite.setScale(0.7f, 0.7f);
                window.draw(sprite);
            }
        }
        position += interval;
    }



}



void Shop::render()
{
        window.clear();
        
        window.draw(background);
        window.draw(pasek);
        buykernel1.handleMouseInteraction();
        buykernel1.draw();
        buykernel2.handleMouseInteraction();
        buykernel2.draw();
        buykernel3.handleMouseInteraction();
        buykernel3.draw();
        window.draw(price1);
        window.draw(price2);
        window.draw(price3);
       

        xPos = 220;
        for (int i = 0; i < letter.size(); ++i) {
            xPos += 140;
             if (letter[i] != 0) { 
            text.setString(std::to_string(letter[i]));
            text.setPosition(xPos, 750); // Ustawienie pozycji na stałe poza pętlą rysowania
            window.draw(text);
         }
        }

pieniadze.setString(zlotowkiStr);
pieniadze.setPosition(100, 100);
window.draw(pieniadze);

        tableforunder();
         window.draw(skrzynka);
        window.display();
}