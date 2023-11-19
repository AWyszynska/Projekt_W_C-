
#include "garden.h" 
#include "guziksklep.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

Garden::Garden(sf::RenderWindow& window) : window(window),
zlotowkiFile("zlotowki_value.txt"),
    sadzonka(window, sf::Vector2f(285, 690), sf::Vector2f(100, 100)), isRunning(true),
    exit(window, sf::Vector2f(50, 50), sf::Vector2f(100, 100)),
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

    if (!exittextur.loadFromFile("aazdj/wyjscie.png")) {
    std::cout<<"blad\n";
   }
   exit.setTexture(exittextur);

   if (!skrzynkazdj.loadFromFile("aazdj/skrzynka.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    skrzynka.setTexture(skrzynkazdj);
    skrzynka.setPosition(950.0f, 0.0f);
    skrzynka.setScale(0.5f, 0.5f);

     if (!font.loadFromFile("Flottflott.ttf")) {
            std::cout << "Error loading font file!" << std::endl;
        }
         else{
            std::cout << "działa" << std::endl;
        }
 zlotowkiText.setFont(font);
    zlotowkiText.setCharacterSize(30);
    zlotowkiText.setFillColor(sf::Color::Black);
    zlotowkiText.setPosition(1000, 90); // Set position as needed
    zlotowkiText.setString("Zlotowki: " + std::to_string(zlotowkiValue));

    if (zlotowkiFile.is_open()) {
        zlotowkiFile >> zlotowkiValue;
        zlotowkiFile.close();
    }

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
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);

            if (exit.isHoveredButton()) {
                switchTofarm();
            }
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
        exit.handleMouseInteraction();
        exit.draw();
        window.draw(skrzynka);
         std::ifstream zlotowkiFile("zlotowki_value.txt");
        zlotowkiText.setString(std::to_string(zlotowkiValue));
        window.draw(zlotowkiText);
        window.display();
}

void Garden::switchTofarm() {

    Game game(window);
    game.run();
}
























