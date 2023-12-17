
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
        position += interval;
    }
            xPos = 180;
        for (int i = 0; i < intvalues.size(); ++i) {

        xPos += 140;
         if (intvalues[i] != 0) { 
            text.setString(std::to_string(intvalues[i]));
            text.setPosition(xPos, 125); 
            window.draw(text);
         }
        }
}


