
#include "openall.h" 

Openall::Openall(sf::RenderWindow& window,std::vector<char> charvalues,std::vector<int> intvalues)
: window(window),charvalues(charvalues),intvalues(intvalues)  {
    
}
void Openall::drawtank(){
if (!werehousephoto.loadFromFile("aazdj/magazynn.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    werehouse.setTexture(werehousephoto);
    werehouse.setPosition(100.0f, 50.0f);
    werehouse.setScale(0.8f, 0.8f);
    window.draw(werehouse);
    for (int i = 0; i < charvalues.size(); i++ ) {
    std::cout<<intvalues[i]<<std::endl;
    }

}
void Openall::addsToPasek(){
    position = 170;
    int interval = 150;
int displayedValues = 0;
int displayedVal = 0;
    for (int i = 0; i < charvalues.size(); i++ ) {
        if (charvalues[i] == 'P' ) {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {

                sprite1.setTexture(obraz1);
                //sf::Sprite sprite1(obraz1);
    sprite1.setPosition(position,125); 
                sprite1.setScale(0.15f, 0.15f);
                window.draw(sprite1);

            }
        } else if (charvalues[i] == 'M') {
           
            if (obraz2.loadFromFile("aazdj/nasionamarchewka.png")) {
                //sf::Sprite sprite2(obraz2);
                sprite2.setTexture(obraz2);
                sprite2.setPosition(position,125); 
                sprite2.setScale(0.7f, 0.7f);
                window.draw(sprite2);
            }
        } else if (charvalues[i] == 'T') {

            if (obraz3.loadFromFile("aazdj/nasionatruskawka.png")) {
                //sf::Sprite sprite3(obraz3);
                sprite3.setTexture(obraz3);
                sprite3.setPosition(position + 10,125); 
                sprite3.setScale(0.7f, 0.7f);
                window.draw(sprite3);

            }
        }
        else if (charvalues[i] == 'C') {

            if (carrottolinephoto.loadFromFile("aazdj/carrot.png")) {
                //sf::Sprite sprite3(obraz3);
               carrottoline.setTexture(carrottolinephoto);
                carrottoline.setPosition(position - 5 ,125); 
                carrottoline.setScale(0.25f, 0.25f);
                window.draw(carrottoline);


            }
        }
        else if (charvalues[i] == 'S') {

            if (strawberrytolinephoto.loadFromFile("aazdj/truskawka.png")) {
                //sf::Sprite sprite3(obraz3);
                strawberrytoline.setTexture(strawberrytolinephoto);
                strawberrytoline.setPosition(position - 10,125); 
                strawberrytoline.setScale(0.3f, 0.3f);
                window.draw(strawberrytoline);


            }
        }
        else if (charvalues[i] == 'J') {

            if (obraz4.loadFromFile("zdjeciasad/nasionajablka.png")) {
                sprite4.setTexture(obraz4);
                sprite4.setPosition(position,125); 
                sprite4.setScale(0.4f, 0.4f);
                window.draw(sprite4);

            }
        }
        else if (charvalues[i] == 'G') {

            if (obraz5.loadFromFile("zdjeciasad/nasionagruszki.png")) {
                 sprite5.setTexture(obraz5);
                sprite5.setPosition(position,125); 
                sprite5.setScale(0.35f, 0.35f);
                window.draw(sprite5);

            }
        }
        else if (charvalues[i] == 'Z') {

            if (obraz6.loadFromFile("zdjeciasad/nasionkosliwa.png")) {
                sprite6.setTexture(obraz6);
                sprite6.setPosition(position,125); 
                sprite6.setScale(0.4f, 0.4f);
                window.draw(sprite6);

            }
        }
        position += interval;
    }
            xPos = 180;
        for (int i = 0; i < intvalues.size(); ++i) {

        xPos += 140;
         if (intvalues[i] != 0) { 
            text.setString(std::to_string(intvalues[i]));
            text.setPosition(xPos, 425); 
            window.draw(text);
         }
        }
}
/*
void Openall::ReplaceXY(){
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);
           // if (exit.isHoveredButton()) {
               // switchTofarm();
          //  }
    for(int i = 0; i < charvalues.size(); i++){
        
    }
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

*/
























