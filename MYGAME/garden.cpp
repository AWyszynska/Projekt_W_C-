
#include "garden.h" 
#include "guziksklep.h" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>



Garden::Garden(sf::RenderWindow& window) : window(window),
zlotowkiFile("zlotowki_value.txt"),
     isRunning(true),
    exit(window, sf::Vector2f(50, 50), sf::Vector2f(100, 100)),
    isSadzonkaPressed(false),currentImage(0)  {
    window.setFramerateLimit(60);

    if (!backgroundTexture.loadFromFile("aazdj/ogrodgrafikapopr.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    background.setTexture(backgroundTexture);


    if (!psze1.loadFromFile("aazdj/sadzonka1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    if (!tru1.loadFromFile("aazdj/truskawka1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
   if (!mar1.loadFromFile("aazdj/marchewka1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

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

void Garden::loadPositions() {
    std::ifstream positionsFile("ogrod/positions.txt");
    if (positionsFile.is_open()) {
        int position;
        while (positionsFile >> position) {
            positionss.push_back(position);
        }
        positionsFile.close();
    } else {
        std::cerr << "Unable to open positions file!" << std::endl;
    }
}



void Garden::loadTimes() {
 std::ifstream timeFile("ogrod/czaszamkniecieogrod.txt");
    if (timeFile.is_open()) {
        std::string line;
        if (std::getline(timeFile, line)) {
            std::tm timeInfo = {};

            // Parsowanie daty i czasu ze wzorcem przy użyciu sscanf
            char day[4], month[4];
            int dayNum, hour, min, sec, year;

            if (std::sscanf(line.c_str(), "%3s %3s %d %d:%d:%d %d",
                            day, month, &dayNum, &hour, &min, &sec, &year) == 7) {

                // Konwersja nazw miesięcy i dni tygodnia na liczby
                const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
                const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

                for (int i = 0; i < 12; ++i) {
                    if (month == std::string(months[i])) {
                        timeInfo.tm_mon = i;
                        break;
                    }
                }

                for (int i = 0; i < 7; ++i) {
                    if (day == std::string(days[i])) {
                        timeInfo.tm_wday = i;
                        break;
                    }
                }

                timeInfo.tm_mday = dayNum;
                timeInfo.tm_hour = hour;
                timeInfo.tm_min = min;
                timeInfo.tm_sec = sec;
                timeInfo.tm_year = year - 1900;

                std::time_t timeValue = std::mktime(&timeInfo);
                std::chrono::system_clock::time_point savedTime = std::chrono::system_clock::from_time_t(timeValue);

                std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
                difference = currentTime - savedTime;
differenceInSeconds = difference.count();
                
            } else {
                std::cerr << "Failed to parse time!" << std::endl;
            }
        }
        timeFile.close();
    } else {
        std::cerr << "Unable to open the file to read time!" << std::endl;
    }
}





void Garden::changeImage() {

     for (size_t i = 0; i < planting.size(); ++i) {
bool foundExisting = false;
   
         DisplayedImage newImage;





        if (planting[i] == 'P' && i >= displayedImages.size()) {
           
            newImage.sprite.setTexture(psze1);

        

             if(positionss.size()>0){
            newImage.positionX = positionss[0];
            positionss.erase(positionss.begin());
            }
            else if(positions.size()>0){
            newImage.positionX = positions[0];
            positions.erase(positions.begin());
            }
            else{
            newImage.positionX = currentX;
            }

            newClock.restart(); // Resetowanie czasu dla nowego zegara
            clocksadzonki.push_back(newClock);
            clocksadzonki[i].restart();
            newImage.sprite.setPosition(newImage.positionX, 520.0f);
             currentX += imageSpacing;
            newImage.sprite.setScale(0.15f, 0.15f);
             if(timess.size()>0){

            newImage.timer = sf::seconds(timess[0]) + sf::seconds(differenceInSeconds);
            timess.erase(timess.begin() );
             }
            else{
            newImage.timer  = sf::Time::Zero;
             }
            displayedImages.push_back(newImage);
        }

        else if(planting[i] == 'M' && i >= displayedImages.size()){
    newImage.sprite.setTexture(mar1);
                if(positionss.size()>0){
            newImage.positionX = positionss[0];
            positionss.erase(positionss.begin());
            }
            else if(positions.size()>0){
            newImage.positionX = positions[0];
            positions.erase(positions.begin());
            }
            else{
            newImage.positionX = currentX;
            }
    newImage.sprite.setPosition(newImage.positionX + 13.0f, 528.0f);
    currentX += imageSpacing;
    newImage.sprite.setScale(0.2f, 0.2f);

            newClock.restart(); // Resetowanie czasu dla nowego zegara
            clocksadzonki.push_back(newClock);
            clocksadzonki[i].restart();
                         if(timess.size()>0){

newImage.timer = sf::seconds(timess[0] ) + sf::seconds(differenceInSeconds);
timess.erase(timess.begin());
             }
            else{
            newImage.timer  = sf::Time::Zero;
             }

            displayedImages.push_back(newImage);
        }

    else if(planting[i] == 'T' && i >= displayedImages.size()){
    newImage.sprite.setTexture(tru1);
             if(positionss.size()>0){
            newImage.positionX = positionss[0];
            positionss.erase(positionss.begin());
            }
            else if(positions.size()>0){
            newImage.positionX = positions[0];
            positions.erase(positions.begin());
            }
            else{
            newImage.positionX = currentX;
            }
    newImage.sprite.setPosition(newImage.positionX - 2.0f, 486.0f);
    currentX += imageSpacing;
    newImage.sprite.setScale(0.2f, 0.2f);

 
            newClock.restart(); // Resetowanie czasu dla nowego zegara
            clocksadzonki.push_back(newClock);
            clocksadzonki[i].restart();
                         if(timess.size()>0){

newImage.timer = sf::seconds(timess[0]) + sf::seconds(differenceInSeconds);
timess.erase(timess.begin());
             }
            else{
            newImage.timer  = sf::Time::Zero;
             }

            displayedImages.push_back(newImage);
    }



if (planting[i] == 'P' && timess.size() > 0) {
        if (displayedImages[i].timer.asSeconds()  >= 10 && !displayedImages[i].isThirdImageDisplayed) {
            if (!psze2.loadFromFile("aazdj/pszenica3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(psze2);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  + 20.0f, 430.0f);

            displayedImages[i].sprite.setScale(0.35f, 0.35f);
            displayedImages[i].isThirdImageDisplayed = true;
        } else if (displayedImages[i].timer.asSeconds() >= 5 && !displayedImages[i].isThirdImageDisplayed) {
            if (!psze3.loadFromFile("aazdj/pszenica2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(psze3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  - 20.0f, 453.0f);

            displayedImages[i].sprite.setScale(0.35f, 0.35f);
        }
       }

       else if (planting[i] == 'P') {
        if (displayedImages[i].timer.asSeconds()  >= 10 && !displayedImages[i].isThirdImageDisplayed) {
            if (!psze2.loadFromFile("aazdj/pszenica3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(psze2);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  + 20.0f, 430.0f);

            displayedImages[i].sprite.setScale(0.35f, 0.35f);
            displayedImages[i].isThirdImageDisplayed = true;
        } else if (displayedImages[i].timer.asSeconds() >= 5 && !displayedImages[i].isThirdImageDisplayed) {
            if (!psze3.loadFromFile("aazdj/pszenica2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(psze3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  - 20.0f, 453.0f);

            displayedImages[i].sprite.setScale(0.35f, 0.35f);
        }
       }
else if (planting[i] == 'M') {
        if (displayedImages[i].timer.asSeconds() >= 20 && !displayedImages[i].isThirdImageDisplayed) {

            if (!mar3.loadFromFile("aazdj/marchewka3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(mar3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  - 15.0f , 452.0f);
            displayedImages[i].sprite.setScale(0.6f, 0.6f);
            displayedImages[i].isThirdImageDisplayed = true; 
        }

        else if (displayedImages[i].timer.asSeconds() >= 10 && !displayedImages[i].isThirdImageDisplayed) {

            if (!mar2.loadFromFile("aazdj/marchewka2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(mar2);
            
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX - 15.0f, 490.0f);
            displayedImages[i].sprite.setScale(0.9f, 0.9f);
            
        }
    }
else if (planting[i] == 'T') {

        if (displayedImages[i].timer.asSeconds() >= 40 && !displayedImages[i].isThirdImageDisplayed) {

            if (!tru3.loadFromFile("aazdj/truskawka3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(tru3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  - 22.0f , 494.0f);
            displayedImages[i].sprite.setScale(0.5f, 0.5f);
            displayedImages[i].isThirdImageDisplayed = true; 
        }

        else if (displayedImages[i].timer.asSeconds() >= 20 && !displayedImages[i].isThirdImageDisplayed) {

            if (!tru2.loadFromFile("aazdj/unnamed.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(tru2);
            
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  - 20.0f, 480.0f);
            displayedImages[i].sprite.setScale(0.5f, 0.5f);
            
        }
    }
        addedtime = clocksadzonki[i].restart();
        displayedImages[i].timer += addedtime; 
    window.draw(displayedImages[i].sprite);

    }
}  

void Garden::loadPlantingInfo() {
    std::ifstream plantingFile("ogrod/planting_info.txt");

    if (plantingFile.is_open()) {
        char plant;

        while (plantingFile >> plant) {
            planting.push_back(plant);
            added++;
        }

        plantingFile.close();
    } else {
        std::cerr << "Unable to open planting info file!" << std::endl;
    }

     std::ifstream plantingFiless("ogrod/pozycjedodatkowe.txt");
      if (plantingFiless.is_open()) {
        float plant;

        while (plantingFiless >> plant) {
            positions.push_back(plant);

        }

        plantingFiless.close();
    } else {
        std::cerr << "Unable to open planting info file!" << std::endl;
    }
    std::ifstream timesFile("ogrod/times.txt");
    if (timesFile.is_open()) {
        float time;
        while (timesFile >> time) {
            timess.push_back(time);
        }
        timesFile.close();
    } else {
        std::cerr << "Unable to open times file!" << std::endl;
    }
}

void Garden::renderTopasek(){
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
void Garden::addToPasek(){
int position = 270;
    int interval = 150;

    for (int i = 0; i < ReadSigns.size(); i++ ) {
        if (ReadSigns[i] == 'P' ) {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {

                sprite1.setTexture(obraz1);
                //sf::Sprite sprite1(obraz1);
                

    sprite1.setPosition(position,700); 
                sprite1.setScale(0.15f, 0.15f);
                if(zasadzonepszenica ){
                window.draw(sprite1);
}

                
            }
        } else if (ReadSigns[i] == 'M') {
           
            if (obraz2.loadFromFile("aazdj/nasionamarchewka.png")) {
                //sf::Sprite sprite2(obraz2);
                sprite2.setTexture(obraz2);
                sprite2.setPosition(position,700); 
                sprite2.setScale(0.7f, 0.7f);
                if(zasadzonemarchew){
                window.draw(sprite2);
                }
            }
        } else if (ReadSigns[i] == 'T') {

            if (obraz3.loadFromFile("aazdj/nasionatruskawka.png")) {
                //sf::Sprite sprite3(obraz3);
                sprite3.setTexture(obraz3);
                sprite3.setPosition(position + 10,700); 
                sprite3.setScale(0.7f, 0.7f);
                if(zasadzonetruskawka){
                window.draw(sprite3);
                }
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


void Garden::run() {

    renderTopasek();
    loadPlantingInfo();
    loadPositions();
    loadTimes();

    while (window.isOpen()) {
        
        handleEvents();
        //handleSadzonkaInteraction();
        //changeImage();
        

        czas = time(nullptr);
        czas_info = localtime(&czas);
render();
        kopcephoto();

        sf::sleep(sf::milliseconds(10));
    }
}

void Garden::handleEvents() {
    sf::Event event;
    if (event.type == sf::Event::Closed) {
        savetimeall();
        savePositions();
        saveTimes();
        savePlantingInfo();
        savepositionAdditional();
        //std::cout  << asctime(czas_info);
        for(int i = 0; i <positionss.size(); i++){
std::cout<<positionss[0]<<std::endl;
        }
        window.close();
    }
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
        savePositions();
        saveTimes();
        savePlantingInfo();
        savetimeall();
        savepositionAdditional();
                for(int i = 0; i <positionss.size(); i++){
std::cout<<positionss[0]<<std::endl;
        }

                window.close();
            } 
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);

            if (exit.isHoveredButton()) {
                switchTofarm();
            }
        else if(added <4){
             if  (sprite1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && zasadzonepszenica) {
                for(int i = 0; i <ReadSigns.size() ; i++){
                         if(ReadSigns[i] == 'P'){
                            if( Readvalues[i] > 1){
                            Readvalues[i] -=1;
                             
                            }
                            else{
                                //PrintLine[i] = false;
                                zasadzonepszenica = false;
                                Readvalues.erase(Readvalues.begin() + i);
                                ReadSigns.erase(ReadSigns.begin() + i);
                            }
                        }

                }
                
               planting.push_back('P');
                isSadzonkaPressed = true; 
                        added++;
            
         
                
               
                }
        
            else if  (sprite2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && zasadzonemarchew) {
                for(int i = 0; i <ReadSigns.size() ; i++){
                        if(ReadSigns[i] == 'M'){
                            if( Readvalues[i] > 1){
                            Readvalues[i] -=1;
                            }
                           else{
                               // PrintLine[i] = false;
                                zasadzonemarchew = false;
                               Readvalues.erase(Readvalues.begin() + i);
                                ReadSigns.erase(ReadSigns.begin() + i);

                            }
                        }

                }
                planting.push_back('M');
                isSadzonkaPressed = true;
                added++; 
            }
            else if  (sprite3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && zasadzonetruskawka) {
                for(int i = 0; i <ReadSigns.size() ; i++){
                        if(ReadSigns[i] == 'T'){
                            if( Readvalues[i] > 1){
                            Readvalues[i] -=1;
                            }
                            else{
                               // PrintLine[i] = false;
                               zasadzonetruskawka = false;
                                Readvalues.erase(Readvalues.begin() + i);
                                ReadSigns.erase(ReadSigns.begin() + i);
                            }
                        }
                }
                planting.push_back('T');
                isSadzonkaPressed = true;
                added++; 
                }
        }
               for (size_t i = 0; i < displayedImages.size(); ++i) {
    if (displayedImages[i].sprite.getGlobalBounds().contains(mousePos) && planting[i] =='P' && displayedImages[i].timer.asSeconds() >= 10) {
        float positionX = displayedImages[i].positionX;

 
        positions.push_back(positionX);
std::sort(positions.begin(), positions.end());

        displayedImages.erase(displayedImages.begin() + i);
        planting.erase(planting.begin() + i);
clocksadzonki.erase(clocksadzonki.begin() + i);
        clicked = true;
        added--; 
        break;
    }
    else if (displayedImages[i].sprite.getGlobalBounds().contains(mousePos) && planting[i] =='M' && displayedImages[i].timer.asSeconds() >= 20) {
        float positionX = displayedImages[i].positionX;


        positions.push_back(positionX);
std::sort(positions.begin(), positions.end());

        displayedImages.erase(displayedImages.begin() + i);
        planting.erase(planting.begin() + i);
clocksadzonki.erase(clocksadzonki.begin() + i);
        clicked = true;
        added--; 
        break;
    }
    else if (displayedImages[i].sprite.getGlobalBounds().contains(mousePos) && planting[i] =='T' && displayedImages[i].timer.asSeconds() >= 40) {
        float positionX = displayedImages[i].positionX;

        positions.push_back(positionX);
std::sort(positions.begin(), positions.end());

        displayedImages.erase(displayedImages.begin() + i);
        planting.erase(planting.begin() + i);
clocksadzonki.erase(clocksadzonki.begin() + i);
        clicked = true;
        added--; 
        break;
    }
}
    }
    }
    }

void Garden::savetimeall() {

//std::time_t currentTime = std::time(nullptr);

    std::ofstream timeFile("ogrod/czaszamkniecieogrod.txt");
    if (timeFile.is_open()) {

        timeFile <<  asctime(czas_info) << std::endl;
        timeFile.close();
    } else {
        std::cerr << "Unable to open the file to save time!" << std::endl;
    }
}

void Garden::savePositions() {
    std::ofstream positionsFile("ogrod/positions.txt");
    if (positionsFile.is_open()) {
       for (DisplayedImage& pos : displayedImages) {
    positionsFile << pos.positionX << std::endl;
}
positionsFile << "" << std::endl;
        positionsFile.close();
    } else {
        std::cerr << "Unable to open positions file!" << std::endl;
    }
}

void Garden::saveTimes() {
    std::ofstream timesFile("ogrod/times.txt");
    if (timesFile.is_open()) {
        for (DisplayedImage& image : displayedImages) {
            timesFile << image.timer.asSeconds() << std::endl;
        }
        timesFile << "" << std::endl;
        timesFile.close();
    } else {
        std::cerr << "Unable to open times file!" << std::endl;
    }
}

void Garden::savePlantingInfo() {
    std::ofstream plantingFile("ogrod/planting_info.txt");
    if (plantingFile.is_open()) {
        for (char plant : planting) {
            plantingFile << plant << std::endl;
        }
        plantingFile << "" << std::endl;
        plantingFile.close();
    } else {
        std::cerr << "Unable to open planting info file!" << std::endl;
    }
}

void Garden::savepositionAdditional(){
        std::ofstream File("ogrod/pozycjedodatkowe.txt");
    if (File.is_open()) {
        for (float plant : positions) {
            File << plant << std::endl;
        }
       //File << "" << std::endl;
        File.close();
    } else {
        std::cerr << "Unable to open planting info file!" << std::endl;
    }
}

void Garden::render()
{
        window.clear();


        
        window.draw(background);
        window.draw(pasek2);
        exit.handleMouseInteraction();
        exit.draw();
        window.draw(skrzynka);
         std::ifstream zlotowkiFile("zlotowki_value.txt");
        zlotowkiText.setString(std::to_string(zlotowkiValue));
        window.draw(zlotowkiText);
        addToPasek();

changeImage();  
std::cout<<added<<std::endl;
for(int i = 0; i<timess.size();i++){
std::cout<<timess[i]<<std::endl;
}
//std::cout << "Różnica czasu wynosi: " << difference.count() << " sekund." << std::endl;
//std::cout<<added<<std::endl;
        window.draw(dokopiec);
        window.draw(dokopiec2);
        window.draw(dokopiec3);
        window.draw(dokopiec4);
        window.display();
}

void Garden::switchTofarm() {
    savePositions();
    saveTimes();
    savePlantingInfo();
    savetimeall();
    savepositionAdditional();

    Game game(window);
    game.run();
}


























