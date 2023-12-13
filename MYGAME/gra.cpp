
#include "gra.h"
#include "guzik.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "garden.h"
#include "shop.h"

Game::Game(sf::RenderWindow& window): window(window),isRunning(true),
zlotowkiFile("zlotowki_value.txt"),
ogrod(window, sf::Vector2f(60, 195), sf::Vector2f(332, 245)),
sad(window, sf::Vector2f(400, 200), sf::Vector2f(335, 340)),
kopalnia(window, sf::Vector2f(50, 479), sf::Vector2f(638, 321)),
hodowla(window, sf::Vector2f(815, 75), sf::Vector2f(340, 339)),
sklep(window, sf::Vector2f(845, 480), sf::Vector2f(340, 339))
{
    window.setFramerateLimit(60);
 if (!font.loadFromFile("Flottflott.ttf")) {
            std::cout << "Error loading font file!" << std::endl;
        }

        text.setFont(font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
 zlotowkiText.setFont(font);
    zlotowkiText.setCharacterSize(30);
    zlotowkiText.setFillColor(sf::Color::Black);
    zlotowkiText.setPosition(1000, 90); 
    zlotowkiText.setString("Zlotowki: " + std::to_string(zlotowkiValue));

    if (zlotowkiFile.is_open()) {
        zlotowkiFile >> zlotowkiValue;
        zlotowkiFile.close();
    }
   


    if (!backgroundTexture.loadFromFile("aazdj/tlopoprawione.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

    background.setTexture(backgroundTexture);
    if (!pasek_zdj.loadFromFile("aazdj/pasek.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    pasek.setTexture(pasek_zdj);
    pasek.setPosition(260.0f, 680.0f);
    pasek.setScale(0.9f, 0.9f);
    if (!skrzynkazdj.loadFromFile("aazdj/skrzynka.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    skrzynka.setTexture(skrzynkazdj);
    skrzynka.setPosition(950.0f, 0.0f);
    skrzynka.setScale(0.5f, 0.5f);




}

void Game::run()
{
     renderTopasek();
    while (window.isOpen()) {
        handleEvents();
        render();
        loadedplace();

    }
}

void Game::loadedplace()
{
        if (!guzikTexture.loadFromFile("aazdj/ggg.png")) {
        std::cout<<"blad\n";
    }
    ogrod.setTexture(guzikTexture);

        if (!sadzdjecie.loadFromFile("aazdj/sad1.png")) {
        std::cout<<"blad\n";
   }
   sad.setTexture(sadzdjecie);

        if (!cavephoto.loadFromFile("aazdj/kopalnia1.png")) {
        std::cout<<"blad\n";
    }
    kopalnia.setTexture(cavephoto);
        if (!animalphoto.loadFromFile("aazdj/hodowla1.png")) {
        std::cout<<"blad\n";
    }
    hodowla.setTexture(animalphoto);
    if (!shopphoto.loadFromFile("aazdj/sklep1.png")) {
        std::cout<<"blad\n";
    }
    sklep.setTexture(shopphoto);
}

void Game::renderTopasek(){
    std::ifstream file("wypisz_values.txt");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }
    while (file >> Signs) {
        if (Signs != ' ') {
            ReadSigns.push_back(Signs);
        }
    }
  file.close();        

        std::ifstream files("letter_values.txt");
    if (!files.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }
    while (files >> valuess) {
        if (valuess != ' ') {
           Readvalues.push_back(valuess);
        }
    }
  files.close(); 
}
void Game::addToPasek(){
int position = 270;
    int interval = 150;

    for (char znak : ReadSigns) {
        if (znak == 'P') {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {
                sf::Sprite sprite(obraz1);
                sprite.setPosition(position,700); 
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
                sprite.setPosition(position + 10,700); 
                sprite.setScale(0.7f, 0.7f);
                window.draw(sprite);
            }
        }
        position += interval;
    }
            xPos = 220;
        for (int i = 0; i < Readvalues.size(); ++i) {
            xPos += 140;
             if (Readvalues[i] != 0) { 
            text.setString(std::to_string(Readvalues[i]));
            text.setPosition(xPos, 750); 
            window.draw(text);
         }
        }




}


void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
                window.close();
            } 
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                clickPosition = sf::Mouse::getPosition(window);
                std::cout << "x: " << clickPosition.x << " y: " << clickPosition.y << std::endl;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);
            
            if (ogrod.isHoveredButton()) {
                switchToGarden();
            }
            if (sklep.isHoveredButton()) {
                switchToShop();
            }
        }
    }
}

void Game::render()
{
        window.clear();
        window.draw(background);
        ogrod.handleMouseInteraction();
        ogrod.draw();
        sad.handleMouseInteraction();
        sad.draw();
        kopalnia.handleMouseInteraction();
        kopalnia.draw();
        hodowla.handleMouseInteraction();
        hodowla.draw();
        sklep.handleMouseInteraction();
        sklep.draw();
        window.draw(pasek);
        window.draw(skrzynka);
        std::ifstream zlotowkiFile("zlotowki_value.txt");
   


zlotowkiText.setString(std::to_string(zlotowkiValue));
    window.draw(zlotowkiText);


   


       addToPasek();
        window.display();
}


void Game::switchToGarden() {

    Garden garden(window);
    garden.run();
}

void Game::switchToShop() {

    Shop shop(window);
    shop.run();
}








































