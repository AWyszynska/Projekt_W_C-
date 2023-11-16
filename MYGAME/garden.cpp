
#include "garden.h" 
#include "guziksklep.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

Garden::Garden(sf::RenderWindow& window) : window(window),
    sadzonka(window, sf::Vector2f(285, 690), sf::Vector2f(100, 100)), isRunning(true),
    isSadzonkaPressed(false),currentImage(0)  {
    window.setFramerateLimit(60);



    if (!backgroundTexture.loadFromFile("aazdj/ogrodgrafikapopr.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    background.setTexture(backgroundTexture);
    timer.restart();

    if (!ziarno1.loadFromFile("aazdj/nasiono1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    sadzonka.setTexture(ziarno1);


    if (!pszenica.loadFromFile("aazdj/sadzonka1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    pszenica2.setTexture(pszenica);
    pszenica2.setPosition(115.0f, 488.0f);
    pszenica2.setScale(0.25f, 0.25f);
}

void Garden::kopcephoto()
{
        if (!pasek.loadFromFile("aazdj/pasek.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

        if (!kopiec.loadFromFile("aazdj/ziemia.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

    pasek2.setTexture(pasek);
    pasek2.setPosition(260.0f, 680.0f);
    pasek2.setScale(0.9f, 0.9f);

    dokopiec.setTexture(kopiec);
    dokopiec2.setTexture(kopiec);
    dokopiec3.setTexture(kopiec);
    dokopiec4.setTexture(kopiec);
    

    dokopiec.setPosition(87.0f, 558.0f);
    dokopiec2.setPosition(365.0f, 558.0f);
    dokopiec3.setPosition(644.0f, 558.0f);
    dokopiec4.setPosition(922.0f, 558.0f);

}

void Garden::handleSadzonkaInteraction() {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

      
        if (mousePosition.x >= 285 && mousePosition.x <= 385 &&
            mousePosition.y >= 690 && mousePosition.y <= 790) {

            isSadzonkaPressed = true; 
            timer.restart();
            
        }
    }
}



void Garden::changeImage() {

    if (isSadzonkaPressed) {

        if (timer.getElapsedTime().asSeconds() >= 10 && !isThirdImageDisplayed) {

            if (!pszenica.loadFromFile("aazdj/pszenica3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            pszenica2.setTexture(pszenica);
            pszenica2.setPosition(115.0f, 488.0f);
            pszenica2.setScale(0.25f, 0.25f);

           
            timer.restart();
            isThirdImageDisplayed = true; 
        }

        else if (timer.getElapsedTime().asSeconds() >= 5 && !isThirdImageDisplayed) {

            if (!pszenica.loadFromFile("aazdj/pszenica2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            pszenica2.setTexture(pszenica);
            pszenica2.setPosition(115.0f, 488.0f);
            pszenica2.setScale(0.25f, 0.25f);
        }
    }
}

void Garden::run() {
    while (window.isOpen()) {
        handleEvents();
        handleSadzonkaInteraction();
        changeImage();  
        render();

        kopcephoto();

        sf::sleep(sf::milliseconds(10));
    }
}

void Garden::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
                window.close();
            } 
    }
}

void Garden::render()
{
        window.clear();


        
        window.draw(background);
        window.draw(pasek2);
        window.draw(dokopiec);
        window.draw(dokopiec2);
        window.draw(dokopiec3);
        window.draw(dokopiec4);

        sadzonka.handleMouseInteraction();
        sadzonka.draw();
    if (isSadzonkaPressed) {
        window.draw(pszenica2);
    }

        window.display();
}

























