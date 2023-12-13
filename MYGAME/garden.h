#pragma once
#include "guzikwarz.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "gra.h"
#include "guzik.h"
#include <fstream>
#include <map>
#include <ctime>
class Garden {

public:
    Garden(sf::RenderWindow& window); 
    void handleSadzonkaInteraction();
    void changeImage();
    void run();

private:

struct DisplayedImage {
    sf::Sprite sprite;
    sf::Clock timer;
    bool isThirdImageDisplayed = false;
    float positionX = 0.0f;
};
std::vector<DisplayedImage> displayedImages;
 bool clicked = false;
 sf::RenderWindow& window;
    sf::Clock timer;
    bool isSadzonkaPressed;
    bool isRunning;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    int currentImage;

std::vector<float> positions;


    sf::Texture ziarno1;
    float currentX = 140.0f; 
    float imageSpacing = 280.0f; 

std::vector<sf::Clock> timeElapsed; 
    float maxDisplayTime = 4.0f; 

std::vector<int> positionss;
std::vector<float> timess;

    Guzik exit;
    sf::Texture exittextur;
    sf::Texture pasek;
    sf::Texture kopiec;
    sf::Texture pszenica;
     int zlotowkiValue = 0;
    sf::Font font; 
    sf::Text zlotowkiText;
    std::ifstream zlotowkiFile;
    int added = 0;

sf::Text text;
 std::vector<char> ReadSigns;
    char Signs;
    std::vector<int> Readvalues;
    int valuess;
    int xPos;

    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;

    sf::Texture psze1;
    sf::Texture psze2;
    sf::Texture psze3;

    sf::Texture mar1;
    sf::Texture mar2;
    sf::Texture mar3;

    sf::Texture tru1;
    sf::Texture tru2;
    sf::Texture tru3;

    sf::Texture obraz1;
    sf::Texture obraz2;
    sf::Texture obraz3;
    sf::Texture skrzynkazdj;
    sf::Sprite skrzynka;
    sf::Sprite pszenica2;
    sf::Sprite pasek2;
    sf::Sprite dokopiec;
    sf::Sprite dokopiec2;
    sf::Sprite dokopiec3;
    sf::Sprite dokopiec4;
    sf::Vector2f position;
    sf::Texture marchewzdj;
    sf::Sprite marchew;
    sf::Texture truskawkazdj;
    sf::Sprite truskawka;
    sf::Vector2f originalScale;
   std::vector<char> planting;  
char plantt;

time_t czas; 
tm* czas_info;

std::vector<sf::Sprite> pszenicaSprites;

    void handleEvents();
    void render();
    void kopcephoto();
    void switchTofarm();
    void renderTopasek();
    void addToPasek();
    void savePositions();
    void saveTimes();
    void savePlantingInfo();
    void savetimeall();
    void loadPlantingInfo();
    void loadPositions();
    void loadTimes();
    void savepositionAdditional();
};
