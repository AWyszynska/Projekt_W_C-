#include <SFML/Graphics.hpp>
#include <iostream>
#include "gra.h"
#include "guzik.h"
#include "menu.h"
#include "garden.h"
#include "guzikwarz.h"

int main() {


    //Menu menu;
    //menu.run();

    // After the menu, create and run the Game class
    sf::RenderWindow window(sf::VideoMode(1200, 800), "handlarz");
    window.setFramerateLimit(60);

    static Garden garden(window);
    garden.run();

    return 0;
}
