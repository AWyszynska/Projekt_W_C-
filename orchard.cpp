
#include "orchard.h" 



Orchard::Orchard(sf::RenderWindow& window) : window(window),
zlotowkiFile("zlotowki_value.txt"),
     isRunning(true),
    exit(window, sf::Vector2f(50, 50), sf::Vector2f(100, 100)),
    isSadzonkaPressed(false),currentImage(0),currentX(-25.0f)  {
    window.setFramerateLimit(60);

    if (!backgroundTexture.loadFromFile("zdjeciasad/zdjeciesadu.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    background.setTexture(backgroundTexture);


    if (!tankphoto.loadFromFile("aazdj/magazynn.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    if (!psze1.loadFromFile("zdjeciasad/jablko11.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    if (!tru1.loadFromFile("zdjeciasad/sliwka11.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
   if (!mar1.loadFromFile("zdjeciasad/gruszka11.png"))
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

void Orchard::kopcephoto()
{
    
        if (!pasek.loadFromFile("aazdj/pasek.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

        if (!kopiec.loadFromFile("zdjeciasad/ziemiasad.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

    pasek2.setTexture(pasek);
    pasek2.setPosition(260.0f, 680.0f);
    pasek2.setScale(0.9f, 0.9f);

    dokopiec.setTexture(kopiec);
    dokopiec2.setTexture(kopiec);
    dokopiec3.setTexture(kopiec);
    dokopiec.setScale(0.4f, 0.4f);
    dokopiec2.setScale(0.4f, 0.4f);
    dokopiec3.setScale(0.4f, 0.4f);
    

    dokopiec.setPosition(187.0f, 575.0f);
    dokopiec2.setPosition(465.0f, 575.0f);
    dokopiec3.setPosition(752.0f, 575.0f);


}

void Orchard::loadPositions() {
    std::ifstream positionsFile("zdjeciasad/pozycjadrzewa.txt");
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



void Orchard::loadTimes() {
 std::ifstream timeFile("zdjeciasad/czascalydrzewa.txt");
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





void Orchard::changeImage() {

     for (size_t i = 0; i < planting.size(); ++i) {
bool foundExisting = false;
   
         DisplayedImage newImage;





        if (planting[i] == 'J' && i >= displayedImages.size()) {
           
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
            newImage.sprite.setPosition(newImage.positionX, 480.0f);
             currentX += imageSpacing;
            newImage.sprite.setScale(0.2f, 0.2f);
             if(timess.size()>0){

            newImage.timer = sf::seconds(timess[0]) + sf::seconds(differenceInSeconds);
            timess.erase(timess.begin() );
             }
            else{
            newImage.timer  = sf::Time::Zero;
             }
            displayedImages.push_back(newImage);
        }

        else if(planting[i] == 'G' && i >= displayedImages.size()){
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
    newImage.sprite.setPosition(newImage.positionX + 300.0f, 490.0f);
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

    else if(planting[i] == 'Z' && i >= displayedImages.size()){
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
    newImage.sprite.setPosition(newImage.positionX + 290.0f, 456.0f);
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


       else if (planting[i] == 'J') {
        if (displayedImages[i].timer.asSeconds()  >= 10 && !displayedImages[i].isThirdImageDisplayed) {
            if (!psze2.loadFromFile("zdjeciasad/jablko3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(psze2);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  - 90.0f, 190.0f);

            displayedImages[i].sprite.setScale(0.6f, 0.6f);
            displayedImages[i].isThirdImageDisplayed = true;
        } else if (displayedImages[i].timer.asSeconds() >= 5 && !displayedImages[i].isThirdImageDisplayed) {
            if (!psze3.loadFromFile("zdjeciasad/jablko2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(psze3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX - 65.0f, 243.0f);

            displayedImages[i].sprite.setScale(0.7f, 0.7f);
        }
       }
else if (planting[i] == 'G') {
        if (displayedImages[i].timer.asSeconds() >= 20 && !displayedImages[i].isThirdImageDisplayed) {

            if (!mar3.loadFromFile("zdjeciasad/gruszka3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(mar3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  + 195.0f , 212.0f);
            displayedImages[i].sprite.setScale(0.6f, 0.6f);
            displayedImages[i].isThirdImageDisplayed = true; 
        }

        else if (displayedImages[i].timer.asSeconds() >= 10 && !displayedImages[i].isThirdImageDisplayed) {

            if (!mar2.loadFromFile("zdjeciasad/gruszka2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(mar2);
            
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX + 210.0f, 230.0f);
            displayedImages[i].sprite.setScale(0.7f, 0.7f);
            
        }
    }
else if (planting[i] == 'Z') {

        if (displayedImages[i].timer.asSeconds() >= 40 && !displayedImages[i].isThirdImageDisplayed) {

            if (!tru3.loadFromFile("zdjeciasad/sliwka3.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(tru3);
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  + 220.0f , 234.0f);
            displayedImages[i].sprite.setScale(0.6f, 0.6f);
            displayedImages[i].isThirdImageDisplayed = true; 
        }

        else if (displayedImages[i].timer.asSeconds() >= 20 && !displayedImages[i].isThirdImageDisplayed) {

            if (!tru2.loadFromFile("zdjeciasad/sliwka2.png")) {
                std::cerr << "Błąd podczas wczytywania tła." << std::endl;
            }
            displayedImages[i].sprite.setTexture(tru2);
            
            displayedImages[i].sprite.setPosition(displayedImages[i].positionX  + 223.0f, 290.0f);
            displayedImages[i].sprite.setScale(0.6f, 0.6f);
            
        }
    }
        addedtime = clocksadzonki[i].restart();
        displayedImages[i].timer += addedtime; 
    window.draw(displayedImages[i].sprite);

    }
}  

void Orchard::addstorage(){
    if (!pointsphoto.loadFromFile("aazdj/kropki.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    points.setTexture(pointsphoto);
    points.setPosition(830.0f, 725.0f);
    points.setScale(0.4f, 0.4f);
    window.draw(points);
}



void Orchard::loadPlantingInfo() {
    std::ifstream plantingFile("zdjeciasad/plantingdrzewa.txt");

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

     std::ifstream plantingFiless("zdjeciasad/pozycjedodatkowedrzewa.txt");
      if (plantingFiless.is_open()) {
        float plant;

        while (plantingFiless >> plant) {
            positions.push_back(plant);

        }

        plantingFiless.close();
    } else {
        std::cerr << "Unable to open planting info file!" << std::endl;
    }
    std::ifstream timesFile("zdjeciasad/czasdrzewka.txt");
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

void Orchard::renderTopasek(){
    std::ifstream file("wypisz_values.txt");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }
    while (file >> Signs) {
        if (Signs != ' ') {
            ReadSigns.push_back(Signs);
        }
    }
   // ReadSigns << "" << std::endl;
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
    //Readvalues << "" << std::endl;
  files.close(); 
}
void Orchard::addToPasek(){
    position = 270;
    int interval = 150;
int displayedValues = 0;
int displayedVal = 0;
    for (int i = 0; i < ReadSigns.size(); i++ ) {
        if (displayedValues >= 4) {
            break; // Przerwij pętlę po wyświetleniu 3 wartości
        }
        if (ReadSigns[i] == 'P' ) {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {

                sprite1.setTexture(obraz1);
                //sf::Sprite sprite1(obraz1);
    sprite1.setPosition(position,700); 
                sprite1.setScale(0.15f, 0.15f);
                if(zasadzonepszenica ){
                window.draw(sprite1);
                displayedValues++;
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
                displayedValues++;
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
                displayedValues++;
                }
            }
        }
        else if (ReadSigns[i] == 'C') {

            if (carrottolinephoto.loadFromFile("aazdj/carrot.png")) {
                //sf::Sprite sprite3(obraz3);
               carrottoline.setTexture(carrottolinephoto);
                carrottoline.setPosition(position - 5 ,700); 
                carrottoline.setScale(0.25f, 0.25f);
                window.draw(carrottoline);
                displayedValues++;

            }
        }
        else if (ReadSigns[i] == 'S') {

            if (strawberrytolinephoto.loadFromFile("aazdj/truskawka.png")) {
                //sf::Sprite sprite3(obraz3);
                strawberrytoline.setTexture(strawberrytolinephoto);
                strawberrytoline.setPosition(position - 10,700); 
                strawberrytoline.setScale(0.3f, 0.3f);
                window.draw(strawberrytoline);
                displayedValues++;

            }
        }
        else if (ReadSigns[i] == 'J') {//A

            if (obraz4.loadFromFile("zdjeciasad/nasionajablka.png")) {
                sprite4.setTexture(obraz4);
                sprite4.setPosition(position,690); 
                sprite4.setScale(0.4f, 0.4f);
                window.draw(sprite4);
                displayedValues++;
            }
        }
        else if (ReadSigns[i] == 'G') {//E

            if (obraz5.loadFromFile("zdjeciasad/nasionagruszki.png")) {
                sprite5.setTexture(obraz5);
                sprite5.setPosition(position,690); 
                sprite5.setScale(0.35f, 0.35f);
                window.draw(sprite5);
                displayedValues++;
            }
        }
        else if (ReadSigns[i] == 'Z') {//F

            if (obraz6.loadFromFile("zdjeciasad/nasionkosliwa.png")) {
                sprite6.setTexture(obraz6);
                sprite6.setPosition(position,690); 
                sprite6.setScale(0.4f, 0.4f);
                window.draw(sprite6);
                displayedValues++;
            }
        }
        else if (ReadSigns[i] == 'A') {//F

            if (obraz7.loadFromFile("zdjeciasad/jablkozdjecie.png")) {
                sprite7.setTexture(obraz7);
                sprite7.setPosition(position,690); 
                sprite7.setScale(0.2f, 0.2f);
                window.draw(sprite7);
                displayedValues++;
            }
        }
        else if (ReadSigns[i] == 'E') {//gruszka

            if (obraz8.loadFromFile("zdjeciasad/gruszkazdjecie.png")) {
                sprite8.setTexture(obraz8);
                sprite8.setPosition(position,690); 
                sprite8.setScale(0.2f, 0.2f);
                window.draw(sprite8);
                displayedValues++;
            }
        }
        else if (ReadSigns[i] == 'F') {//sliwka

            if (obraz9.loadFromFile("zdjeciasad/sliwkazdjecie.png")) {
                sprite9.setTexture(obraz9);
                sprite9.setPosition(position+10,690); 
                sprite9.setScale(0.25f, 0.25f);
                window.draw(sprite9);
                displayedValues++;
            }
        }
        position += interval;
    }
            xPos = 220;
        for (int i = 0; i < Readvalues.size(); ++i) {
            if (displayedVal  >= 4) {
            break; // Przerwij pętlę po wyświetleniu 3 wartości
        }
        xPos += 140;
         if (Readvalues[i] != 0) { 
            text.setString(std::to_string(Readvalues[i]));
            text.setPosition(xPos, 750); 
            window.draw(text);
            displayedVal ++;
         }
        }
}


void Orchard::run() {

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
//bleeaddtoline();
        sf::sleep(sf::milliseconds(10));
    }
}

void Orchard::handleEvents() {
    sf::Event event;
    if (event.type == sf::Event::Closed) {
        savetimeall();
        savePositions();
        saveTimes();
        savePlantingInfo();
        savepositionAdditional();
        switchplace();
        window.close();
    }
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
        savePositions();
        saveTimes();
        savePlantingInfo();
        savetimeall();
        savepositionAdditional();
        switchplace();

                window.close();
            } 
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);
            if(sorrywiondowisopen){
            if (exit.isHoveredButton()) {
                switchTofarm();
            }
        else if(added <4){
             if  (sprite4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && zasadzonepszenica) {
                for(int i = 0; i <ReadSigns.size() ; i++){
                         if(ReadSigns[i] == 'J'){
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
                
               planting.push_back('J');
                isSadzonkaPressed = true; 
                        added++;
            
         
                
               
                }
        
            else if  (sprite5.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && zasadzonemarchew) {
                for(int i = 0; i <ReadSigns.size() ; i++){
                        if(ReadSigns[i] == 'G'){
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
                planting.push_back('G');
                isSadzonkaPressed = true;
                added++; 
            }
            else if  (sprite6.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && zasadzonetruskawka) {
                for(int i = 0; i <ReadSigns.size() ; i++){
                        if(ReadSigns[i] == 'Z'){
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
                planting.push_back('Z');
                isSadzonkaPressed = true;
                added++; 
                }
        }
               for (size_t i = 0; i < displayedImages.size(); ++i) {
    if (displayedImages[i].sprite.getGlobalBounds().contains(mousePos) && planting[i] =='J' && displayedImages[i].timer.asSeconds() >= 10) {
        float positionX = displayedImages[i].positionX;

 
        positions.push_back(positionX);
std::sort(positions.begin(), positions.end());

        displayedImages.erase(displayedImages.begin() + i);
        planting.erase(planting.begin() + i);
clocksadzonki.erase(clocksadzonki.begin() + i);
       clicked = true;
        added--;
        char znak = 'A'; // Twój znak do dodania
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('A');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'A'){
                        Readvalues[j] += 1;
                        break;
                    }
                }

            
            } 
    }
        
        
    
    else if (displayedImages[i].sprite.getGlobalBounds().contains(mousePos) && planting[i] =='G' && displayedImages[i].timer.asSeconds() >= 20) {
        float positionX = displayedImages[i].positionX;


        positions.push_back(positionX);
std::sort(positions.begin(), positions.end());

        displayedImages.erase(displayedImages.begin() + i);
        planting.erase(planting.begin() + i);
clocksadzonki.erase(clocksadzonki.begin() + i);
        clicked = true;
        added--;
        char znak = 'E'; // Twój znak do dodania
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('E');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'E'){
                        Readvalues[j] += 1;
                        break;
                    }
                }

            
            } 
    }
        

    else if (displayedImages[i].sprite.getGlobalBounds().contains(mousePos) && planting[i] =='Z' && displayedImages[i].timer.asSeconds() >= 10) {
        float positionX = displayedImages[i].positionX;

        positions.push_back(positionX);
std::sort(positions.begin(), positions.end());

        displayedImages.erase(displayedImages.begin() + i);
        planting.erase(planting.begin() + i);
clocksadzonki.erase(clocksadzonki.begin() + i);
        clicked = true;
        added--; 
        char znak = 'F';
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('F');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'F'){
                        Readvalues[j] += 1;
                        break;
                    }
                }
        
    }
}
               } 
            }         
    if(points.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        openwerehouse = !openwerehouse;
        sorrywiondowisopen = !sorrywiondowisopen;
    }
            
            }
       
    
    }
}




void Orchard::savetimeall() {

//std::time_t currentTime = std::time(nullptr);

    std::ofstream timeFile("zdjeciasad/czascalydrzewa.txt");
    if (timeFile.is_open()) {

        timeFile <<  asctime(czas_info) << std::endl;
        timeFile.close();
    } else {
        std::cerr << "Unable to open the file to save time!" << std::endl;
    }
}

void Orchard::savePositions() {
    std::ofstream positionsFile("zdjeciasad/pozycjadrzewa.txt");
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

void Orchard::saveTimes() {
    std::ofstream timesFile("zdjeciasad/czasdrzewka.txt");
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

void Orchard::savePlantingInfo() {
    std::ofstream plantingFile("zdjeciasad/plantingdrzewa.txt");
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

void Orchard::savepositionAdditional(){
        std::ofstream File("zdjeciasad/pozycjedodatkowedrzewa.txt");
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

void Orchard::render()
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
        

changeImage();  
        window.draw(dokopiec);
        window.draw(dokopiec2);
        window.draw(dokopiec3);

        addstorage();
addToPasek();
        if(openwerehouse){
         Openall openall(window,ReadSigns,Readvalues);
    openall.drawtank();
    openall.addsToPasek();
        }
        window.display();
}
void Orchard::switchplace(){
            std::ofstream wypiszFile("wypisz_values.txt");
    if (wypiszFile.is_open()) {
        for (char znak : ReadSigns) {
            wypiszFile << znak << " ";
        }
        wypiszFile.close();
    }
    std::ofstream letterFile("letter_values.txt");
    if (letterFile.is_open()) {
        for (int value : Readvalues) {
            letterFile << value << " ";
        }
        letterFile.close();
    }
}
void Orchard::switchTofarm() {
    savePositions();
    saveTimes();
    savePlantingInfo();
    savetimeall();
    savepositionAdditional();
switchplace();
    Game game(window);
    game.run();
    
}