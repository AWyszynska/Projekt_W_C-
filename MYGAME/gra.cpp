
#include "gra.h"
#include "guzik.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "garden.h"

Game::Game(sf::RenderWindow& window): window(window),isRunning(true),
ogrod(window, sf::Vector2f(60, 195), sf::Vector2f(332, 245)),
sad(window, sf::Vector2f(400, 200), sf::Vector2f(335, 340)),
kopalnia(window, sf::Vector2f(50, 479), sf::Vector2f(638, 321)),
hodowla(window, sf::Vector2f(815, 75), sf::Vector2f(340, 339)),
sklep(window, sf::Vector2f(845, 480), sf::Vector2f(340, 339))
{
    window.setFramerateLimit(60);



    if (!backgroundTexture.loadFromFile("tlopoprawione.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

    background.setTexture(backgroundTexture);


}

void Game::run()
{
    while (window.isOpen()) {
        handleEvents();
        render();
        loadedplace();
    }
}

void Game::loadedplace()
{
        if (!guzikTexture.loadFromFile("ggg.png")) {
        std::cout<<"blad\n";
    }
    ogrod.setTexture(guzikTexture);

        if (!sadzdjecie.loadFromFile("sad1.png")) {
        std::cout<<"blad\n";
   }
   sad.setTexture(sadzdjecie);

        if (!cavephoto.loadFromFile("kopalnia1.png")) {
        std::cout<<"blad\n";
    }
    kopalnia.setTexture(cavephoto);
        if (!animalphoto.loadFromFile("hodowla1.png")) {
        std::cout<<"blad\n";
    }
    hodowla.setTexture(animalphoto);
    if (!shopphoto.loadFromFile("sklep1.png")) {
        std::cout<<"blad\n";
    }
    sklep.setTexture(shopphoto);
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

        window.display();
}


void Game::switchToGarden() {

    Garden garden(window);
    garden.run();
}










































