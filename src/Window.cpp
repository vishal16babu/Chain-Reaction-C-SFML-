#include "Window.h"

sf::RenderWindow* Window::window = NULL;
Window::Window()
{
    //ctor
}

void Window::createWindow()
{
}

sf::RenderWindow* Window::getWindow()
{
    if(window == NULL)
            window = new sf::RenderWindow(sf::VideoMode(800, 600), "Happy Birthday", sf::Style::Close );

    return window;
}
