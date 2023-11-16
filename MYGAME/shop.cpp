
#include "shop.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

Shop::Shop(sf::RenderWindow& window) : window(window),
    buykernel1(window, sf::Vector2f(200, 210), sf::Vector2f(100, 100)),
    buykernel2(window, sf::Vector2f(356, 210), sf::Vector2f(100, 100)),
    buykernel3(window, sf::Vector2f(512, 210), sf::Vector2f(100, 100)),
    isRunning(true)  {
    window.setFramerateLimit(60);



    if (!backgroundTexture.loadFromFile("aazdj/sklepzdj.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    background.setTexture(backgroundTexture);



}

void Shop::addprice(){

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
                std::cout << "Kliknięto!\n";
                 zbiornik.push_back(pszenicaznak);
                 licznik = 0; 

        for (char num : zbiornik) {
                         if (num == 'P') {
                            licznik++;
                    }
                    
                    }



            found = false;

            // Sprawdzamy, czy literka jest już w wektorze
            for (char znak : wypisz) {
            if (znak == pszenicaznak) {
                found = true;
                break;
            }
         }

         if (!found) {
        wypisz.push_back(pszenicaznak);
        }

    updateLetterCount(pszenicaznak);
            }
            else if (buykernel2.isHoveredButton()) {//marchewka
            
                std::cout << "Marchewka!\n";
                std::cout << "Rozmiar wektora: " << zbiornik.size() << std::endl;
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

    updateLetterCount(marchewkaznak);
            }
            else if (buykernel3.isHoveredButton()) {//truskawka
               updateLetterCount(truskawkaznak);
            for (char num : wypisz) {
                std::cout << num << " ";
                    
                    }



                std::cout << licznik << std::endl;
                std::cout << "Truskawka!\n";
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

            }
        }
    }
}

void Shop::tableforunder(){
    //if(wypisz.size()>0){
        int position = 270;
    int interval = 150;

    for (char znak : wypisz) {
        if (znak == 'P') {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {
                sf::Sprite sprite(obraz1);
                sprite.setPosition(position,690); 
                sprite.setScale(0.2f, 0.2f);
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

    //}

}

void Shop::updateLetterCount(char letter) {
    // Sprawdź, czy litera jest już w mapie letterCount
    auto it = letterCount.find(letter);
    if (it != letterCount.end()) {
        // Jeśli litera jest już w mapie, zwiększ liczbę wystąpień
        it->second++;
    } else {
        // Jeśli litera nie istnieje, dodaj ją do mapy z liczbą wystąpień ustawioną na 1
        letterCount.insert({letter, 1});
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
            for (const auto& entry : letterCount) {
        std::cout << entry.first << ": " << entry.second << std::endl;
        // Tutaj możesz umieścić te liczby w oknie, na przykład w polu tekstowym lub wypisywać na ekranie gry
    }
        tableforunder();
        window.display();
}