
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include "window.h"
#include<cstdlib>
#include<cstdio>
using namespace std;
class welcome{

    sf::Texture image;
    sf::Sprite sprite;
public:
    welcome(){
sf::RenderWindow *window;
    window = Window::getWindow();
    sf::Clock clock;
if(!image.loadFromFile("gamefiles/sgrid.png"))
            {
                cout<<"unable to load sgrid.png"<<endl;
                return ;
            }
            sprite.setTexture(image);
            window->draw(sprite);

            return ;
    }


};
int main()
{ int w=0;
    sf::RenderWindow *window;//declaring the window
    // create the window
    window = Window::getWindow();

     sf::Music music;
    if(!music.openFromFile("bfiles/Ashritha.wav"))//declaring music objects.If the music files don't exist or cannot be loaded, return.
    {
        cout<<"unable to load file music.wav"<<endl;
        return -1;
    }
    // error
    music.play();
    music.setLoop(true);

     sf::Clock clock;

     while (window->isOpen())
    {

        window->setVerticalSyncEnabled(true);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Texture image;
        sf::Sprite sprite;
         sf::Time elapsed1 = clock.getElapsedTime();
         // run it
          while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }

        }

elapsed1=clock.getElapsedTime();
            if(elapsed1.asSeconds()>0.0){
window->clear();
               // welcome Welcome;
               if(!image.loadFromFile("gamefiles/sgrid.png"))
            {
                cout<<"unable to load sgrid.png"<<endl;
                return -1;
            }
            sprite.setTexture(image);
            window->draw(sprite);
        }

if(w==0){
     sf::Font font;//code for scrolling txt to appear on the screen

            sf::Text text;
            if(!font.loadFromFile("gamefiles/Button T Italic.ttf"))
            {
                cout<<"unable to load Button T Italic.ttf"<<endl;
                return -1;
            }
            // select the font
            text.setFont(font); // font is a sf::Font

            // set the string to display
            text.setString("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou are always there for me, supporting me, encouraging me , listening to me and all those other things that friends do. Happy Birthday!!!.");

            // set the character size
            text.setCharacterSize(24); // in pixels, not points!

            // set the color
            text.setColor(sf::Color::Green);

            // set the text style
            text.setStyle(sf::Text::Bold );
            sf::Time elapsed1 = clock.getElapsedTime();
            if( elapsed1.asSeconds()>0.0 )//code for moving the text on the screen
            {
                text.move(750-60*elapsed1.asSeconds(),0);
            }
            if(elapsed1.asSeconds()>30.0)
            {
                clock.restart();
                w=1;
                music.openFromFile("bfiles/song2.wav");
                music.play();
            }
             window->draw(text);
}

        window->display();
    }
}
