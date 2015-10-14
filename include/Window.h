#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Window
{
    private:
        static sf::RenderWindow *window;
        Window();
    public:
        void createWindow();
        static sf::RenderWindow* getWindow();


};

#endif // WINDOW_H
