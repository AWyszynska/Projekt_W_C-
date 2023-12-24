#include "shop.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <sstream>

Shop::Shop(sf::RenderWindow& window) : window(window),
    buykernel1(window, sf::Vector2f(210, 210), sf::Vector2f(100, 100)),
    buykernel2(window, sf::Vector2f(376, 210), sf::Vector2f(100, 100)),
    buykernel3(window, sf::Vector2f(542, 210), sf::Vector2f(100, 100)),
    buykernel4(window, sf::Vector2f(712, 210), sf::Vector2f(100, 100)),
    buykernel5(window, sf::Vector2f(878, 210), sf::Vector2f(100, 100)),
    buykernel6(window, sf::Vector2f(195, 360), sf::Vector2f(100, 100)),
    exit(window, sf::Vector2f(50, 50), sf::Vector2f(100, 100)),
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

if (!exittextur.loadFromFile("aazdj/wyjscie.png")) {
        std::cout<<"blad\n";
   }
   exit.setTexture(exittextur);



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
    price1.setPosition(164.0f, 270.0f);
    price1.setScale(0.5f, 0.5f);

    if(!pricesset2.loadFromFile("aazdj/marcena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price2.setTexture(pricesset2);
    price2.setPosition(334.0f, 270.0f);
    price2.setScale(0.5f, 0.5f);

    if(!pricesset3.loadFromFile("aazdj/truskcena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price3.setTexture(pricesset3);
    price3.setPosition(504.0f, 270.0f);
    price3.setScale(0.5f, 0.5f);

    if (!pricesset4.loadFromFile("zdjeciasad/jablkacena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price4.setTexture(pricesset4);
    price4.setPosition(674.0f, 270.0f);
    price4.setScale(0.5f, 0.5f);

    if(!pricesset5.loadFromFile("zdjeciasad/gruszkacena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price5.setTexture(pricesset5);
    price5.setPosition(844.0f, 270.0f);
    price5.setScale(0.5f, 0.5f);

    if(!pricesset6.loadFromFile("zdjeciasad/sliwkacena.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    price6.setTexture(pricesset6);
    price6.setPosition(164.0f, 420.0f);
    price6.setScale(0.5f, 0.5f);
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

    if (!ziar4.loadFromFile("zdjeciasad/nasionajablka.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    buykernel4.setTexture(ziar4);
    if (!ziar5.loadFromFile("zdjeciasad/nasionagruszki.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    buykernel5.setTexture(ziar5);
    if (!ziar6.loadFromFile("zdjeciasad/nasionkosliwa.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    buykernel6.setTexture(ziar6);
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
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);

            if (exit.isHoveredButton()) {
                switchTofarm();
            }



            if (buykernel1.isHoveredButton()) {//pszenica
                 zbiornik.push_back(pszenicaznak);
                 licznik = 0; 

        if (zlotowki >= 10) {
                    zlotowki -= 10;
                    ss.str(""); 
                    ss << zlotowki; 
                    zlotowkiStr = ss.str();

        }


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

        if (zlotowki >= 50) {
                    zlotowki -= 50;
                    ss.str(""); // Clear the stringstream
                    ss << zlotowki; // Update stringstream with the new zlotowki value
                    zlotowkiStr = ss.str();

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
found = false;
        if (zlotowki >= 120) {
                    zlotowki -= 120;
                    ss.str(""); // Clear the stringstream
                    ss << zlotowki; // Update stringstream with the new zlotowki value
                    zlotowkiStr = ss.str();

        }


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




                    else if (buykernel4.isHoveredButton()) {//marchewka
            
                 zbiornik.push_back(jablkoznak);
                 licznik = 0;   
                  found = false;
            for (char znak : wypisz) {
            if (znak == jablkoznak) {
                found = true;
                break;
            }
         }

        if (zlotowki >= 300) {
                    zlotowki -= 300;
                    ss.str(""); // Clear the stringstream
                    ss << zlotowki; // Update stringstream with the new zlotowki value
                    zlotowkiStr = ss.str();

        }


         if (!found) {
        wypisz.push_back(jablkoznak);
        }
    auto it = std::find(wypisz.begin(), wypisz.end(), 'J');
    if (it != wypisz.end()) {
        int position = std::distance(wypisz.begin(), it);
        letter[position]++;
    } 
 
            }
    else if (buykernel5.isHoveredButton()) {//marchewka
            
                 zbiornik.push_back(gruszkaznak);
                 licznik = 0;   
                  found = false;
            for (char znak : wypisz) {
            if (znak == gruszkaznak) {
                found = true;
                break;
            }
         }

        if (zlotowki >= 500) {
                    zlotowki -= 500;
                    ss.str(""); // Clear the stringstream
                    ss << zlotowki; // Update stringstream with the new zlotowki value
                    zlotowkiStr = ss.str();

        }


         if (!found) {
        wypisz.push_back(gruszkaznak);
        }
    auto it = std::find(wypisz.begin(), wypisz.end(), 'G');
    if (it != wypisz.end()) {
        int position = std::distance(wypisz.begin(), it);
        letter[position]++;
    } 
 
            }
    else if (buykernel6.isHoveredButton()) {//marchewka
            
                 zbiornik.push_back(sliwkaznak);
                 licznik = 0;   
                  found = false;
            for (char znak : wypisz) {
            if (znak == sliwkaznak) {
                found = true;
                break;
            }
         }

        if (zlotowki >= 700) {
                    zlotowki -= 700;
                    ss.str(""); // Clear the stringstream
                    ss << zlotowki; // Update stringstream with the new zlotowki value
                    zlotowkiStr = ss.str();

        }


         if (!found) {
        wypisz.push_back(sliwkaznak);
        }
    auto it = std::find(wypisz.begin(), wypisz.end(), 'Z');
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
        }else if (znak == 'J') {

            if (obraz4.loadFromFile("zdjeciasad/nasionajablka.png")) {
                sf::Sprite sprite(obraz4);
                sprite.setPosition(position,690); 
                sprite.setScale(0.4f, 0.4f);
                window.draw(sprite);
            }
        }else if (znak == 'G') {

            if (obraz5.loadFromFile("zdjeciasad/nasionagruszki.png")) {
                sf::Sprite sprite(obraz5);
                sprite.setPosition(position,690); 
                sprite.setScale(0.35f, 0.35f);
                window.draw(sprite);
            }
        }else if (znak == 'Z') {

            if (obraz6.loadFromFile("zdjeciasad/nasionkosliwa.png")) {
                sf::Sprite sprite(obraz6);
                sprite.setPosition(position,690); 
                sprite.setScale(0.4f, 0.4f);
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

        buykernel4.handleMouseInteraction();
        buykernel4.draw();
        buykernel5.handleMouseInteraction();
        buykernel5.draw();
        buykernel6.handleMouseInteraction();
        buykernel6.draw();
        exit.handleMouseInteraction();
        exit.draw();
        window.draw(price1);
        window.draw(price2);
        window.draw(price3);
        window.draw(price4);
        window.draw(price5);
        window.draw(price6);

        xPos = 220;
        for (int i = 0; i < letter.size(); ++i) {
            xPos += 140;
             if (letter[i] != 0) { 
            text.setString(std::to_string(letter[i]));
            text.setPosition(xPos, 750);
            window.draw(text);
         }
        }


        tableforunder();
         window.draw(skrzynka);
       
pieniadze.setString(zlotowkiStr);
pieniadze.setPosition(1000, 90);
window.draw(pieniadze);
 window.display();
}

void Shop::switchTofarm() {

        std::ofstream wypiszFile("wypisz_values.txt");
    if (wypiszFile.is_open()) {
        for (char znak : wypisz) {
            wypiszFile << znak << " ";
        }
        wypiszFile.close();
    }
    std::ofstream letterFile("letter_values.txt");
    if (letterFile.is_open()) {
        for (int value : letter) {
            letterFile << value << " ";
        }
        letterFile.close();
    }
    std::ofstream zlotowkiFile("zlotowki_value.txt");
    if (zlotowkiFile.is_open()) {
        zlotowkiFile << zlotowki;
        zlotowkiFile.close();
    }

    Game game(window);
    game.run();
}
