#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include "window.h"
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

int criticalmass(int i,int j);
void arti(int gamespace[8][6],int*x,int*y);
int sum(int temp[8][6]);
int sum2(int temp[8][6]);
bool winmove(int temp[8][6],int l,int m);
void highlight(int gamespace[8][6],int i,int j,int w);
void plotter(int gamespace[8][6],float t);
void fission1(int gamespace[8][6],int i, int j);
void fission2(int gamespace[8][6],int i, int j);
bool terminationcondition(int gamespace[8][6]);
class Game
{
//class game is defined in order to use it to implement saving of the game.
public:

    int x;//denotes the state of the window in the 2 player saved game
    int y;//denotes the state of the window in the single player saved game
    int array1[8][6];//denotes the state of the gamespace in the 2 player saved game
    int array2[8][6];// denotes the state of the gamespace in the single player saved game
Game(){x=1;y=1;
   for(int i=0; i<8; i++) //initialise the all the array elements  to zero
    {
        for(int j=0; j<6; j++)
        {array1[8][6]=0;array2[8][6]=0;
        }}
}

};



int main()
{
    //declarations
    int* l;
    int* k;
    int* c;
    c=new int;
    *c=0;
    l=new int;
    k=new int;
    Game game;

    FILE*fptr;//declaring file pointers,will use them to save the game.
    FILE*fout;
    fptr=fopen("regedit","rb+");//opening file regedit in rb+ mode
    fout=fopen("regedit","rb+");
    if (fptr == NULL)
    {
        //if the file doesn't already exist, it is created.
        fclose(fptr);
        fopen("regedit","wb");
        fclose(fptr);
        fptr=fopen("regedit","rb+");
        cout << "created database file" << endl;
    }
    if (fout == NULL)
    {
        cout << "created database file" << endl;

    }

    sf::RenderWindow *window;//declaring the window

    int w=0;//represents the state of the window in the gameplay
    int x;//represents he co-ordinates of the mouse pointer
    int y;//represents the co-ordinates of the mouse pointer
    int a;
    int b;
    bool m=false;
    int undoarray[8][6];//array storing the previous step in the game
    int gamespace[8][6];//grid of the game
    for(int i=0; i<8; i++) //initialise all the array elements  to zero
    {
        for(int j=0; j<6; j++)
        {
            gamespace[i][j]=0;
        }
    }


    // create the window
    window = Window::getWindow();


    sf::Music music;
    if(!music.openFromFile("music.wav"))//declaring music objects.If the music files don't exist or cannot be loaded, return.
    {
        cout<<"unable to load file music.wav"<<endl;
        return -1;
    }
    // error
    music.play();
    music.setLoop(true);

    sf::Music button;
    if(!button.openFromFile("sound.wav"))//declaring music objects.If the music files don't exist or cannot be loaded, return
    {
        cout<<"unable to load file sound.wav"<<endl;
        return -1;
    }
    sf::Music gameover;
    if(!gameover.openFromFile("gameover.wav"))//declaring music objects.If the music files don't exist or cannot be loaded, return
    {
        cout<<"unable to load file gameover.wav"<<endl;
        return -1;
    }

    sf::Music claps;
    if(!claps.openFromFile("claps.wav"))//declaring music objects.If the music files don't exist or cannot be loaded, return
    {
        cout<<"unable to load file claps.wav"<<endl;
        return -1;
    }


    sf::Clock clock;
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Chain Reaction");

    // run the program as long as the window is open
    while (window->isOpen())
    {

        window->setVerticalSyncEnabled(true);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Texture texture;
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


            if(event.type == sf::Event::KeyPressed&&(w==4||w==6||w==7||w==9||w==10||w==11||w==12))
            {
                if (event.key.code == sf::Keyboard::Escape||event.key.code == sf::Keyboard::BackSpace)
                {
                    w=1;
                }
            }//code for returning to main menu when escape or backspace is pressed.


            if(event.type == sf::Event::KeyPressed&&(w==0))
            {
                w=1;


            }//code for going to main menu on pressing any key

            if (event.type == sf::Event::MouseButtonPressed)
            {
                music.stop();
                button.play();//music stops when mouse button is pressed.

                if (event.mouseButton.button == sf::Mouse::Left&&(w==1))
                {
                    //code for menu

                    x=event.mouseButton.x;
                    y=event.mouseButton.y ;
                    if(x>510&&y>167&&x<640&&y<218)
                    {
                        w=2;//represents single player game
                        window->clear();
                    }
                    if(x>510&&y>252&&x<640&&y<302)
                    {
                        w=3;//represents 2 player game
                        window->clear();
                    }
                    if(x>648&&y>167&&x<773&&y<218)
                    {
                        w=13;//represents saved single player game
                    }
                    if(x>648&&y>252&&x<773&&y<302)
                    {
                        w=14;//represents saved two player game
                    }
                    if(x>540&&y>335&&x<750&&y<390)
                    {
                        w=11;//represents instructions
                    }
                    if(x>540&&y>433&&x<750&&y<479)
                    {
                        w=4;//represents credits
                    }
                    if(x>540&&y>506&&x<750&&y<551)
                    {
                        window->close();
                    }
                }


                if (event.mouseButton.button == sf::Mouse::Left&&((w==3)||(w==5)||(w==2)||(w==8)||(w==11)))
                {
                    //code for the execution of back button
                    x=event.mouseButton.x;
                    y=event.mouseButton.y ;

                    if(x>720&&y>10&&x<800&&y<35)
                    {
                        w=1;
                        for(int i=0; i<8; i++) //initialise the all the array elements  to zero
                        {
                            for(int j=0; j<6; j++)
                            {
                                gamespace[i][j]=0;
                            }
                        }
                        m=false;
                    }

                    if(x>680&&y>45&&x<730&&y<90&&((w==3)||(w==5)||(w==2)||(w==8)))
                    {
                        //code for saving the game
                        rewind(fptr);



                        if(w==3||w==5)
                        {
                            game.x=w;
                            for(int i=0; i<8; i++) //copying all elements of game space into array1
                            {
                                for(int j=0; j<6; j++)
                                {

                                    game.array1[i][j]=gamespace[i][j];
                                }
                            }
                        }
                        if(w==2||w==8)
                        {
                            game.y=w;
                            for(int i=0; i<8; i++) //copying all elements of gamespace into array2
                            {
                                for(int j=0; j<6; j++)
                                {

                                    game.array2[i][j]=gamespace[i][j];
                                }
                            }
                        }
                        fwrite(&game,sizeof(class Game),1,fptr);
                        rewind(fptr);
                    }


                    if(x>736&&y>40&&x<790&&y<95&&(w!=2))
                    {
                        //code for undoing the last move
                        if(w==3)
                        {
                            w=5;
                        }
                        else
                        {
                            if(w==5)
                            {
                                w=3;
                            }
                            else
                            {
                                if(w==8)
                                {
                                    w=2;
                                }
                            }
                        }
                        for(int i=0; i<8; i++)
                        {
                            for(int j=0; j<6; j++)
                            {
                                gamespace[i][j]=undoarray[i][j];
                            }
                        }
                    }
                    if(x>647&&y>57&&x<750&&y<93&&(w==11))
                    {
                        w=12;
                    }//code for moving to the 2nd page of instructions


                }

            }


        }
        if(w==14)//code for loading saved 1 player game
        {

            rewind(fout);

            fread(&game,sizeof(class Game),1,fout);




            if(game.x==3||game.x==5)
            {
                w=game.x;
                for(int i=0; i<8; i++) //copy all the array elements of the saved game into the current gamespace
                {
                    for(int j=0; j<6; j++)
                    {

                        gamespace[i][j]=game.array1[i][j];
                    }
                }
            }



        }
        if(w==13)//code for loading the saved 2 payer game
        {
            rewind(fout);

            fread(&game,sizeof(class Game),1,fout);




            if(game.y==2||game.y==8)
            {
                w=game.y;
                for(int i=0; i<8; i++) //copy all the array elements in the savedgame array into the current gamespace
                {
                    for(int j=0; j<6; j++)
                    {

                        gamespace[i][j]=game.array2[i][j];
                    }
                }
            }
            rewind(fout);



        }




        if(w==12)//corresponds to the second instructions window
        {
            window->clear();
            if(!texture.loadFromFile("instructions2.png"))
            {
                cout<<"unable to load instructions2.png"<<endl;
                return -1;
            }

            sprite.setTexture(texture);
            window->draw(sprite);
        }
        if(w==11)//corresponds to the first instructions window
        {
            window->clear();
            if(!texture.loadFromFile("instructions1.png"))
            {
                cout<<"unable to load instructions1.png"<<endl;
                return -1;
            }


            sprite.setTexture(texture);

            window->draw(sprite);
        }


        if(w==1)//main menu
        {
            window->clear();
            if(!texture.loadFromFile("4.png"))
            {
                cout<<"unable to load 4.png"<<endl;
                return -1;
            }


            sprite.setTexture(texture);

            window->draw(sprite);
            if (event.type == sf::Event::MouseMoved&&w==1)
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                x=position.x-297;
                y=position.y-116;

//code for highlighting the option in the main menu when mouse moves over it
                if(x>510&&y>167&&x<640&&y<218)
                {
                    if(!texture.loadFromFile("4.1.png"))
                    {
                        cout<<"unable to load 4.1.png"<<endl;
                        return -1;
                    }

                    sprite.setTexture(texture);
                    window->draw(sprite);
                }
                if(x>648&&y>167&&x<773&&y<218)
                {
                    if(!texture.loadFromFile("4.2.png"))
                    {
                        cout<<"unable to load 4.2.png"<<endl;
                        return -1;
                    }

                    sprite.setTexture(texture);

                    // inside the main loop, between window->clear() and window->display()
                    window->draw(sprite);

                }
                if(x>648&&y>252&&x<773&&y<302)
                {
                    if(!texture.loadFromFile("4.4.png"))
                    {
                        cout<<"unable to load 4.4.png"<<endl;
                        return -1;

                    }

                    sprite.setTexture(texture);

                    // inside the main loop, between window->clear() and window->display()
                    window->draw(sprite);


                }
                if(x>510&&y>252&&x<640&&y<302)
                {
                    if(!texture.loadFromFile("4.3.png"))
                    {
                        cout<<"unable to load 4.3.png"<<endl;
                        return -1;
                    }


                    sprite.setTexture(texture);

                    // inside the main loop, between window->clear() and window->display()
                    window->draw(sprite);
                }
                if(x>540&&y>335&&x<750&&y<390)
                {
                    if(!texture.loadFromFile("4.5.png"))
                    {
                        cout<<"unable to load 4.5.png"<<endl;
                        return -1;
                    }


                    sprite.setTexture(texture);

                    // inside the main loop, between window->clear() and window->display()
                    window->draw(sprite);
                }

                if(x>540&&y>433&&x<750&&y<479)
                {
                    if(!texture.loadFromFile("4.6.png"))
                    {
                        cout<<"unable to load 4.6.png"<<endl;
                        return -1;
                    }

                    sprite.setTexture(texture);

                    // inside the main loop, between window->clear() and window->display()
                    window->draw(sprite);
                }

                if(x>540&&y>506&&x<750&&y<551)
                {
                    if(!texture.loadFromFile("4.7.png"))
                {
                    cout<<"unable to load 4.7.png"<<endl;
                    return -1;
                }

                sprite.setTexture(texture);

                // inside the main loop, between window->clear() and window->display()
                window->draw(sprite);
            }
        }
        texture.setSmooth(true);
        }
        if(w==4)//loading credits image when w gets value 4
        {
            window->clear();
            if(!texture.loadFromFile("credits.jpg"))
            {
                cout<<"unable to load credits.jpg"<<endl;
                return -1;
            }

            sprite.setTexture(texture);

            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
        }

        if(w==0)
        {
            //loading startup image when w gets value 0
            window->clear();
            if(!texture.loadFromFile("3.jpg"))
            {
                cout<<"unable to load 3.jpg"<<endl;
                return -1;
            }


            sprite.setTexture(texture);
            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
            sf::Font font;//code for scrolling txt to appear on the screen

            sf::Text text;
            if(!font.loadFromFile("Button T Italic.ttf"))
            {
                cout<<"unable to load Button T Italic.ttf"<<endl;
                return -1;
            }
            // select the font
            text.setFont(font); // font is a sf::Font

            // set the string to display
            text.setString("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome to the world of gaming.Press any key to continue");

            // set the character size
            text.setCharacterSize(24); // in pixels, not points!

            // set the color
            text.setColor(sf::Color::Green);

            // set the text style
            text.setStyle(sf::Text::Bold );
            sf::Time elapsed1 = clock.getElapsedTime();
            if( elapsed1.asSeconds()>0.0 )//code for moving the text on the screen
            {
                text.move(750-50*elapsed1.asSeconds(),0);
            }
            if(elapsed1.asSeconds()>30.0)
            {
                clock.restart();
            }


            // inside the main loop, between window->clear() and window->display()
            window->draw(text);
        }

        if(w==3)//loading the image of the grid
        {
            if(!texture.loadFromFile("p1grid.png"))
            {
                cout<<"unable to load p1grid.png"<<endl;
                return -1;
            }

            music.stop();
            sprite.setTexture(texture);

            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);

            sf::Time elapsed1 = clock.getElapsedTime();
            if(elapsed1.asSeconds()>2.0)
            {
                clock.restart();
            }
            plotter(gamespace,elapsed1.asSeconds());

            if (event.type == sf::Event::MouseMoved&&w==3)
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                x=position.x;
                y=position.y;

                a=(y-194)/65;
                b=(x-395)/65;
                if(a>=0&&b>=0&&a<8&&b<6)
                {
                    //code for highlighting the cell on which the mouse pointer is moved
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(65, 65));
                    rectangle.setOutlineColor(sf::Color::Red);
                    rectangle.setOutlineThickness(5);
                    rectangle.setPosition(65*b+94,65*a+72);
                    rectangle.setFillColor(sf::Color::Black);
                    window->draw(rectangle);
                }
                highlight(gamespace,a,b,w);//function to show the orbs inside he highlighted cell
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Left&&(w==3))
                {

                    x=event.mouseButton.x;//when mouse is left clicked in the cell the current gamespace is copied to undoarray and gamespace is changed accordingly
                    y=event.mouseButton.y;
                    a=(y-75)/65;
                    b=(x-100)/65;
                    if(a>=0&&b>=0&&a<8&&b<6)
                    {
                        if(gamespace[a][b]>=0)
                        {
                            for(int i=0; i<8; i++)
                            {
                                for(int j=0; j<6; j++)
                                {
                                    undoarray[i][j]=gamespace[i][j];
                                }
                            }
                            gamespace[a][b]++;


                            fission1(gamespace,a,b);//function that sees if there are any fissions possible and undergoes them

                            plotter(gamespace,elapsed1.asSeconds());//function that plots the orbs on the grid
                            w=5;//the window changes to player2's turn

                            if(m)//terminationcondition must not be checked the first time as after the first turn there's only one ball.
                            {
                                if(terminationcondition(gamespace))
                                {
                                    w=6 ;//i the game gets over, window changes to w=6 and claps music starts
                                    music.stop();
                                    button.stop();
                                    gameover.stop();
                                    claps.play();
                                }
                            }
                            m=true;

                        }
                    }


                }
            }

        }

        if(w==5)
        {
            if(!texture.loadFromFile("p2grid.png"))
            {
                cout<<"unable to load p2grid.png"<<endl;
                return -1;
            }//green grid is loaded


            sprite.setTexture(texture);

            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);

            sf::Time elapsed1 = clock.getElapsedTime();
            if(elapsed1.asSeconds()>2.0)
            {
                clock.restart();
            }
            plotter(gamespace,elapsed1.asSeconds());;

            if (event.type == sf::Event::MouseMoved&&w==5)
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                x=position.x;//code to highlight the cell on which the mouse pointer is moved
                y=position.y;

                a=(y-194)/65;
                b=(x-395)/65;
                if(a>=0&&b>=0&&a<8&&b<6)
                {
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(65, 65));
                    rectangle.setOutlineColor(sf::Color::Green);
                    rectangle.setOutlineThickness(5);
                    rectangle.setPosition(65*b+94,65*a+72);
                    rectangle.setFillColor(sf::Color::Black);
                    window->draw(rectangle);
                }
                highlight(gamespace,a,b,w);//function puts the orbs inside the highlighted cells
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Right&&(w==5))
                {

                    x=event.mouseButton.x;
                    y=event.mouseButton.y;
                    a=(y-75)/65;
                    b=(x-100)/65;
                    if(a>=0&&b>=0&&a<8&&b<6)//when the mouse is right clicked on a cell the corresponding array element is incremented if it is valid position
                    {
                        if(gamespace[a][b]<=0)
                        {
                            for(int i=0; i<8; i++) //copy the gamespace into undoarray
                            {
                                for(int j=0; j<6; j++)
                                {
                                    undoarray[i][j]=gamespace[i][j];
                                }
                            }
                            gamespace[a][b]--;
                            fission2(gamespace,a,b);//function checks for possible fissions and undergoes them
                            plotter(gamespace,elapsed1.asSeconds());;//function that plots the orbs on to the grid
                            w=3;
                            if(terminationcondition(gamespace))
                            {
                                w=7;//if game gets over w becomes 7 and the player2 wins
                                music.stop();
                                button.stop();
                                gameover.stop();
                                claps.play();
                            }

                        }
                    }



                }
            }



        }
        if(w==6)
        {
            //load image p1w if player1 wins
            window->clear();
            if(!texture.loadFromFile("p1w.jpg"))
            {
                cout<<"unable to load p1w.jpg"<<endl;
            }
            sprite.setTexture(texture);
            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
            for(int i=0; i<8; i++) //reset all the values in the gamespace array and change m back to false
            {
                for(int j=0; j<6; j++)
                {
                    gamespace[i][j]=0;
                }
            }
            m=false;

        }


        if(w==7)
        {
            window->clear();
//load image p2w as player2 wins
            if(!texture.loadFromFile("p2w.jpg"))
            {
                cout<<"unable to load p2w.jpg"<<endl;
                return -1;
            }
            sprite.setTexture(texture);
            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
            for(int i=0; i<8; i++) //reset the values of the elements of the gamespace array and set m back to false
            {
                for(int j=0; j<6; j++)
                {
                    gamespace[i][j]=0;
                }
            }
            m=false;


        }

        if(w==2)
        {
//load the player's grid

            if(!texture.loadFromFile("pgrid.png"))
            {
                cout<<"unable to load pgrid.jpg"<<endl;
                return -1;
            }


            sprite.setTexture(texture);

            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
            sf::Time elapsed1 = clock.getElapsedTime();
            if(elapsed1.asSeconds()>2.0)
            {
                clock.restart();
            }
            plotter(gamespace,elapsed1.asSeconds());;
            if (event.type == sf::Event::MouseMoved&&w==2)
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                x=position.x;
                y=position.y;//code for highlighting the cell on which the mouse pointer is moved

                a=(y-194)/65;
                b=(x-395)/65;
                if(a>=0&&b>=0&&a<8&&b<6)
                {
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(65, 65));
                    rectangle.setOutlineColor(sf::Color::Red);
                    rectangle.setOutlineThickness(5);
                    rectangle.setPosition(65*b+94,65*a+72);
                    rectangle.setFillColor(sf::Color::Black);
                    window->draw(rectangle);
                }
                highlight(gamespace,a,b,w);//function to plot the orbs on to the highlighted cells in the grid
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Left&&(w==2))
                {

                    x=event.mouseButton.x;//when mouse's left button is pressed in a valid cell the array is incremented
                    y=event.mouseButton.y;
                    a=(y-75)/65;
                    b=(x-100)/65;
                    if(a>=0&&b>=0&&a<8&&b<6)
                    {
                        if(gamespace[a][b]>=0)
                        {
                            for(int i=0; i<8; i++) //copies the contents of the gamespace to undoarray
                            {
                                for(int j=0; j<6; j++)
                                {
                                    undoarray[i][j]=gamespace[i][j];
                                }
                            }

                            gamespace[a][b]++;
                            fission1(gamespace,a,b);
                            plotter(gamespace,elapsed1.asSeconds());;//function that plots the orbs inthe grid according t the array
                            w=8;
                            if(m)
                            {
                                if(terminationcondition(gamespace))
                                {
                                    w=9 ;
                                    music.stop();
                                    button.stop();
                                    gameover.stop();
                                    claps.play();


                                }
                            }
                            m=true;

                        }
                    }


                }
            }

        }





        if(w==8)
        {

//system's turn load image sgrid
            if(!texture.loadFromFile("sgrid.png"))
            {
                cout<<"unable to load sgrid.png"<<endl;
                return -1;
            }
            sprite.setTexture(texture);
// inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
            sf::Time elapsed1 = clock.getElapsedTime();
            if(elapsed1.asSeconds()>2.0)
            {
                clock.restart();
            }
            plotter(gamespace,elapsed1.asSeconds());;

            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Right&&w==8)//system's turn calls arti function
                {
                    arti(gamespace,l,k);
                    if(l==NULL||k==NULL)
                    {
                        cout<<"memory allocation failure"<<endl;
                    }
                    else if(*l>=0&&*k>=0&&*l<8&&*k<6)
                    {
                        if(gamespace[*l][*k]<=0)//
                        {

                            gamespace[*l][*k]--;//if the arti function returns valid indices, the gamespace is correspondingly modified
                            fission2(gamespace,*l,*k);
                            plotter(gamespace,elapsed1.asSeconds());;
                            w=2;
                            if(terminationcondition(gamespace))//if game ends in this turn, system wins and w is changed to 10
                            {
                                w=10;
                                music.stop();
                                button.stop();
                                claps.stop();
                                gameover.play();

                            }
                        }

                    }

                }
            }
        }




        if(w==9)
        {
            window->clear();//if w=9, player wins load image uwin

            if(!texture.loadFromFile("uwin.jpg"))
            {
                cout<<"unable to load uwin.jpg"<<endl;
            }
            sprite.setTexture(texture);
            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);
            texture.setSmooth(true);
            for(int i=0; i<8; i++) //reset all the array elements  to zero
            {
                for(int j=0; j<6; j++)
                {
                    gamespace[i][j]=0;
                }
            }
            m=false;
        }


        if(w==10)
        {
            window->clear();//system wins so load the image ulost


            if(!texture.loadFromFile("ulost.jpg"))
            {
                cout<<"unable to load ulost.jpg"<<endl;
                return -1;
            }
            sprite.setTexture(texture);


            // inside the main loop, between window->clear() and window->display()
            window->draw(sprite);

            texture.setSmooth(true);
            for(int i=0; i<8; i++) //reset all the array elements  to zero
            {
                for(int j=0; j<6; j++)
                {
                    gamespace[i][j]=0;
                }
            }
            m=false;
        }
        // draw everything here...
        // window->draw(...);

        // end the current frame
        window->display();
    }
    fclose(fptr);
    fclose(fout);
    delete l ;
    delete k;
    delete c ;//deallocations
    return 0;
}


void fission1(int gamespace[8][6],int i, int j)
{


    if(i<0||i>7||j<0||j>5||gamespace[i][j]<criticalmass(i,j))//fission occurs only inside the grid and ends when it does not exceed critical mass
    {
        return;
    }
    else
    {
        gamespace[i][j]=0;//the orb explodes if it exceeds critical mass
        if(j<5)
        {
            if(gamespace[i][j+1]<0)

            {

                gamespace[i][j+1]=(-(gamespace[i][j+1]))+1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i][j+1]++;//if they hit orbs of same colour they increase in mass
            }
        }
        //this  recursion occurs until the fission terminates
        if(i<7)
        {
            if(gamespace[i+1][j]<0)
            {
                gamespace[i+1][j]=(-(gamespace[i+1][j]))+1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i+1][j]++;//if they hit orbs of same colour they increase in mass
            }
        }
        //this  recursion occurs until the fission terminates
        if(j>0)
        {
            if(gamespace[i][j-1]<0)
            {
                gamespace[i][j-1]=(-(gamespace[i][j-1]))+1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i][j-1]++;//if they hit orbs of same colour they increase in mass
            }
        }
        //this  recursion occurs until the fission terminates

        if(i>0)
        {
            if(gamespace[i-1][j]<0)
            {
                gamespace[i-1][j]=(-(gamespace[i-1][j]))+1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i-1][j]++;//if they hit orbs of same colour they increase in mass
            }
        }


        if(j<5)
        {
            fission1(gamespace,i,j+1);
        }
        if(i<7)
        {
            fission1(gamespace,i+1,j);
        }
        if(i>0)
        {
            fission1(gamespace,i-1,j);
        }
        if(j>0) //this  recursion occurs until the fission terminates
        {
            fission1(gamespace,i,j-1);
        }
        return;
    }
}


void fission2(int gamespace[8][6],int i, int j)
{

    if(i<0||i>7||j<0||j>5||-gamespace[i][j]<criticalmass(i,j))//fission occurs only inside the grid and ends when it does not exceed critical mass
    {
        return;
    }
    else
    {
        gamespace[i][j]=0;//the orb explodes if it exceeds critical mass
        if(j<5)
        {
            if(gamespace[i][j+1]>0)
            {
                gamespace[i][j+1]=(-(gamespace[i][j+1]))-1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i][j+1]--;//if they hit orbs of same colour they increase in mass
            }
        }
        //this  recursion occurs until the fission terminates
        if(i<7)
        {
            if(gamespace[i+1][j]>0)//the orb explodes if it exceeds critical mass
            {
                gamespace[i+1][j]=(-(gamespace[i+1][j]))-1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i+1][j]--;//if they hit orbs of same colour they increase in mass
            }
        }
        if(j>0)
        {

            if(gamespace[i][j-1]>0)//the orb explodes if it exceeds critical mass
            {
                gamespace[i][j-1]=(-(gamespace[i][j-1]))-1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i][j-1]--;//if they hit orbs of same colour they increase in mass
            }
        }

        if(i>0)
        {
            if(gamespace[i-1][j]>0)//the orb explodes if it exceeds critical mass
            {
                gamespace[i-1][j]=(-(gamespace[i-1][j]))-1;//if they hit orbs of other colour they change its colour
            }
            else
            {
                gamespace[i-1][j]--;//if they hit orbs of same colour they increase in mass
            }
        }


        if(j<5)
        {
            fission2(gamespace,i,j+1);
        }
        if(i<7)
        {
            fission2(gamespace,i+1,j);
        }
        if(i>0)
        {
            fission2(gamespace,i-1,j);
        }
        if(j>0)
        {
            fission2(gamespace,i,j-1);
        }
        return;
    }
}


int criticalmass(int i,int j)//Critical mass of different positions is defined in this function
{
    if((i==7&&j==5)||(i==7&&j==0)||(i==0&&j==5)||(i==0&&j==0))
    {
        return 2;
    }
    if((i==7&&(j!=0&&j!=5))||(i==0&&(j!=0&&j!=5))||(j==5&&(i!=0&&i!=7))||(j==0&&(i!=0&&i!=7)))
    {
        return 3;
    }
    else if(!((i==7&&j==5)||(i==7&&j==0)||(i==0&&j==5)||(i==0&&j==0)))
    {
        return 4;
    }
}


bool terminationcondition(int gamespace[8][6])//this function checks if all the elements are  non negative or all the elements are non positive
//in which case the game ends
{

    if(sum(gamespace)!=1)
    {
        int i,j;
        int k=0;
        for(i=0; i<8; i++)
        {
            for(j=0; j<6; j++)
            {
                if(gamespace[i][j]>=0)
                {
                    k++;
                }
            }

        }
        if(k==48)
        {
            return true;
        }
        k=0;
        for(i=0; i<8; i++)
        {
            for(j=0; j<6; j++)
            {
                if(gamespace[i][j]<=0)
                {
                    k++;
                }
            }

        }
        if(k==48)
        {
            return true;
        }
    }

    return false;

}



void plotter(int gamespace[8][6],float t)//this functions plots the orbs in to the grid by reading the array
{

    sf::RenderWindow *window;
    window = Window::getWindow();
    sf::Texture texture;
    sf::Sprite sprite;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {

            if(gamespace[i][j]==1)
            {
                if(gamespace[i][j]==criticalmass(i,j)-1)//for including vibration effects for orbs that have reached criticalmass
                {
                    if(t<1.0)
                    {
                        sf::CircleShape circle(12.5+2.5*t);
                        circle.setFillColor(sf::Color(200,0,0));//1st part of the vibration cycle

                        circle.setPosition(65*j+110,65*i+90);
                        window->draw(circle);
                    }
                    else
                    {
                        sf::CircleShape circle(17.5-2.5*t);
                        circle.setFillColor(sf::Color(200,0,0));

                        circle.setPosition(65*j+110,65*i+90);//2nd pat of the vibration cycle
                        window->draw(circle);
                    }
                }
                else//draw just the circle if criticalmass hasnt reached
                {
                    sf::CircleShape circle(15);
                    circle.setFillColor(sf::Color(200,0,0));

                    circle.setPosition(65*j+110,65*i+90);
                    window->draw(circle);
                }
            }
            if(gamespace[i][j]==2)
            {
                if(gamespace[i][j]==criticalmass(i,j)-1)
                {
                    if(t<1.0)
                    {

                        sf::CircleShape circle(15);
                        circle.setFillColor(sf::Color(200,0,0));
                        circle.setPosition(65*j+105-5*t,65*i+90);
                        window->draw(circle);
                        sf::CircleShape circle1(15);
                        circle1.setFillColor(sf::Color(200,0,0));
                        circle1.setPosition(65*j+115+5*t,65*i+90);
                        window->draw(circle1);
                    }
                    else
                    {
                        sf::CircleShape circle(15);
                        circle.setFillColor(sf::Color(200,0,0));
                        circle.setPosition(65*j+95+5*t,65*i+90);

                        window->draw(circle);
                        sf::CircleShape circle1(15);
                        circle1.setFillColor(sf::Color(200,0,0));
                        circle1.setPosition(65*j+125-5*t,65*i+90);
                        window->draw(circle1);
                    }
                }
                else
                {
                    sf::CircleShape circle(15);
                    circle.setFillColor(sf::Color(200,0,0));
                    circle.setPosition(65*j+120,65*i+90);
                    window->draw(circle);
                    sf::CircleShape circle1(15);
                    circle1.setFillColor(sf::Color(200,0,0));
                    circle1.setPosition(65*j+100,65*i+90);
                    window->draw(circle1);
                }

            }


            if(gamespace[i][j]==3)
            {

                if(t<1.0)
                {
                    sf::CircleShape circle(12.5);
                    circle.setFillColor(sf::Color(200,0,0));
                    circle.setPosition(65*j+110,65*i+85-5*t-2.5);
                    window->draw(circle);
                    sf::CircleShape circle1(12.5);
                    circle1.setFillColor(sf::Color(200,0,0));
                    circle1.setPosition(65*j+115.7+4.3*t,65*i+87.5+2.5*t);
                    window->draw(circle1);
                    sf::CircleShape circle2(12.5);
                    circle2.setFillColor(sf::Color(200,0,0));
                    circle2.setPosition(65*j+104.3-4.3*t,65*i+87.5+2.5*t);
                    window->draw(circle2);
                }
                else
                {
                    sf::CircleShape circle(12.5);
                    circle.setFillColor(sf::Color(200,0,0));
                    circle.setPosition(65*j+110,65*i+75+5*t-2.5);
                    window->draw(circle);
                    sf::CircleShape circle1(12.5);
                    circle1.setFillColor(sf::Color(200,0,0));
                    circle1.setPosition(65*j+124.3-4.3*t,65*i+92.5-2.5*t);
                    window->draw(circle1);
                    sf::CircleShape circle2(12.5);
                    circle2.setFillColor(sf::Color(200,0,0));
                    circle2.setPosition(65*j+95.7+4.3*t,65*i+92.5-2.5*t);
                    window->draw(circle2);
                }

            }


            if(gamespace[i][j]==-1)
            {
                if(gamespace[i][j]==-criticalmass(i,j)+1)
                {
                    if(t<1.0)
                    {
                        sf::CircleShape circle(12.5+2.5*t);
                        circle.setFillColor(sf::Color(100,250,50));

                        circle.setPosition(65*j+110,65*i+90);
                        window->draw(circle);
                    }
                    else
                    {
                        sf::CircleShape circle(17.5-2.5*t);
                        circle.setFillColor(sf::Color(100,250,50));

                        circle.setPosition(65*j+110,65*i+90);
                        window->draw(circle);
                    }
                }
                else
                {
                    sf::CircleShape circle(15);
                    circle.setFillColor(sf::Color(100,250,50));
                    circle.setPosition(65*j+110,65*i+90);
                    window->draw(circle);
                }
            }

            if(gamespace[i][j]==-2)
            {
                if(gamespace[i][j]==-criticalmass(i,j)+1)
                {
                    if(t<1.0)
                    {
                        sf::CircleShape circle(15);
                        circle.setFillColor(sf::Color(100,250,50));
                        circle.setPosition(65*j+105-5*t,65*i+90);
                        window->draw(circle);
                        sf::CircleShape circle1(15);
                        circle1.setFillColor(sf::Color(100,250,50));
                        circle1.setPosition(65*j+115+5*t,65*i+90);
                        window->draw(circle1);
                    }
                    else
                    {
                        sf::CircleShape circle(15);
                        circle.setFillColor(sf::Color(100,250,50));
                        circle.setPosition(65*j+95+5*t,65*i+90);

                        window->draw(circle);
                        sf::CircleShape circle1(15);
                        circle1.setFillColor(sf::Color(100,250,50));
                        circle1.setPosition(65*j+125-5*t,65*i+90);
                        window->draw(circle1);
                    }
                }
                else
                {
                    sf::CircleShape circle(15);
                    circle.setFillColor(sf::Color(100,250,50));
                    circle.setPosition(65*j+120,65*i+90);
                    window->draw(circle);
                    sf::CircleShape circle1(15);
                    circle1.setFillColor(sf::Color(100,250,50));
                    circle1.setPosition(65*j+100,65*i+90);
                    window->draw(circle1);
                }

            }


            if(gamespace[i][j]==-3)
            {
                if(t<1.0)
                {
                    sf::CircleShape circle(12.5);
                    circle.setFillColor(sf::Color(100,250,50));
                    circle.setPosition(65*j+110,65*i+85-5*t-2.5);
                    window->draw(circle);
                    sf::CircleShape circle1(12.5);
                    circle1.setFillColor(sf::Color(100,250,50));
                    circle1.setPosition(65*j+115.7+4.3*t,65*i+87.5+2.5*t);
                    window->draw(circle1);
                    sf::CircleShape circle2(12.5);
                    circle2.setFillColor(sf::Color(100,250,50));
                    circle2.setPosition(65*j+104.3-4.3*t,65*i+87.5+2.5*t);
                    window->draw(circle2);
                }
                else
                {
                    sf::CircleShape circle(12.5);
                    circle.setFillColor(sf::Color(100,250,50));
                    circle.setPosition(65*j+110,65*i+75+5*t-2.5);
                    window->draw(circle);
                    sf::CircleShape circle1(12.5);
                    circle1.setFillColor(sf::Color(100,250,50));
                    circle1.setPosition(65*j+124.3-4.3*t,65*i+92.5-2.5*t);
                    window->draw(circle1);
                    sf::CircleShape circle2(12.5);
                    circle2.setFillColor(sf::Color(100,250,50));
                    circle2.setPosition(65*j+95.7+4.3*t,65*i+92.5-2.5*t);
                    window->draw(circle2);
                }
            }
        }
    }
    return;
}


void arti(int gamespace[8][6],int*x,int*y)
{

    sf::Clock clock;
    int a;
    int temp[8][6];
    int min;
    int min2;
    bool m=true;
    a=rand()%4;//for making the AI randomized so that its next move cannot be easily predicted a can take values0,1,2,3
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp[i][j]=gamespace[i][j];//copy te current gamespace into a temporary array
        }
    };

    if(a==0)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<6; j++)
            {
                if(temp[i][j]>0)//if the cell is occupied by player already, then continue
                {
                    continue;
                }
                else
                {
                    //if the cell isn't occupied by player, then put the orb n that position and see what happens
                    temp[i][j]--;
                    fission2(temp,i,j);

                    if(winmove(temp,i,j))
                    {
                        for(int l=0; l<8; l++)
                        {
                            for(int k=0; k<6; k++)
                            {
                                temp[l][k]=gamespace[l][k];
                            }
                        };
                        continue;
                    }
                    if(m)
                    {
                        min=sum(temp);
                        *x=i;
                        *y=j;
                        min2=sum2(temp);
                        m=false;
                    }
                    else
                    {
                        if(sum(temp)<min)
                        {
                            min=sum(temp);
                            *x=i;
                            *y=j;
                            min2=sum2(temp);
                        }
                        else
                        {
                            if(sum(temp)==min)
                            {
                                if(sum2(temp)<min2)
                                {
                                    min=sum(temp);
                                    *x=i;
                                    *y=j;
                                    min2=sum2(temp);
                                }
                            }
                        }
                    }
                      for(int l=0; l<8; l++)
                {
                    for(int k=0; k<6; k++)
                    {
                        temp[l][k]=gamespace[l][k];
                    }
                };

                }


            }
        }
        if(m)
        {
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<6; j++)
                {
                    if(temp[i][j]>0)
                    {
                        continue;
                    }
                    else
                    {
                        *x=i;
                        *y=j;
                    }
                }
            }
        }
    }
    if(a==1)
    {
        for(int i=7; i>=0; i--)
        {
            for(int j=5; j>=0; j--)
            {
                if(temp[i][j]>0)
                {
                    continue;
                }
                else
                {
                    temp[i][j]--;
                    fission2(temp,i,j);
                    if(winmove(temp,i,j))
                    {
                        for(int l=0; l<8; l++)
                        {
                            for(int k=0; k<6; k++)
                            {
                                temp[l][k]=gamespace[l][k];
                            }
                        };
                        continue;
                    }
                    if(m)
                    {
                        min=sum(temp);
                        *x=i;
                        *y=j;
                        min2=sum2(temp);
                        m=false;
                    }
                    else
                    {
                        if(sum(temp)<min)
                        {
                            min=sum(temp);
                            *x=i;
                            *y=j;
                            min2=sum2(temp);
                        }
                        else
                        {
                            if(sum(temp)==min)
                            {
                                if(sum2(temp)<min2)
                                {
                                    min=sum(temp);
                                    *x=i;
                                    *y=j;
                                    min2=sum2(temp);
                                }
                            }
                        }
                    }
                     for(int l=0; l<8; l++)
                {
                    for(int k=0; k<6; k++)
                    {
                        temp[l][k]=gamespace[l][k];
                    }
                };

                }

            }
        }
        if(m)
        {
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<6; j++)
                {
                    if(temp[i][j]>0)
                    {
                        continue;
                    }
                    else
                    {
                        *x=i;
                        *y=j;
                    }
                }
            }
        }

    }

    if(a==2)
    {
        for(int i=0; i<6; i++)
        {
            for(int j=7; j>=0; j--)
            {
                if(temp[j][i]>0)
                {
                    continue;
                }
                else
                {
                    temp[j][i]--;
                    fission2(temp,j,i);

                    if(winmove(temp,i,j))
                    {
                        for(int l=0; l<8; l++)
                        {
                            for(int k=0; k<6; k++)
                            {
                                temp[l][k]=gamespace[l][k];
                            }
                        };
                        continue;
                    }
                    if(m)
                    {
                        min=sum(temp);
                        *x=j;
                        *y=i;
                        min2=sum2(temp);
                        m=false;
                    }
                    else
                    {
                        if(sum(temp)<min)
                        {
                            min=sum(temp);
                            *x=j;
                            *y=i;
                            min2=sum2(temp);
                        }
                        else
                        {
                            if(sum(temp)==min)
                            {
                                if(sum2(temp)<min2)
                                {
                                    min=sum(temp);
                                    *x=j;
                                    *y=i;
                                    min2=sum2(temp);
                                }
                            }
                        }
                    }
                     for(int l=0; l<8; l++)
                {
                    for(int k=0; k<6; k++)
                    {
                        temp[l][k]=gamespace[l][k];
                    }
                };
                }



            }
        }
        if(m)
        {
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<6; j++)
                {
                    if(temp[i][j]>0)
                    {
                        continue;
                    }
                    else
                    {
                        *x=i;
                        *y=j;
                    }
                }
            }
        }
    }
    if(a==3)
    {
        for(int i=5; i>=0; i--)
        {
            for(int j=0; j<8; j++)
            {
                if(temp[j][i]>0)
                {
                    continue;
                }
                else
                {
                    temp[j][i]--;
                    fission2(temp,j,i);

                    if(winmove(temp,i,j))
                    {
                        for(int l=0; l<8; l++)
                        {
                            for(int k=0; k<6; k++)
                            {
                                temp[l][k]=gamespace[l][k];
                            }
                        };
                        continue;
                    }
                    if(m)
                    {
                        min=sum(temp);
                        *x=j;
                        *y=i;
                        min2=sum2(temp);
                        m=false;
                    }
                    else
                    {
                        if(sum(temp)<min)
                        {
                            min=sum(temp);
                            *x=j;
                            *y=i;
                            min2=sum2(temp);
                        }
                        else
                        {
                            if(sum(temp)==min)
                            {
                                if(sum2(temp)<min2)
                                {
                                    min=sum(temp);
                                    *x=j;
                                    *y=i;
                                    min2=sum2(temp);
                                }
                            }
                        }
                    }
                      for(int l=0; l<8; l++)
                {
                    for(int k=0; k<6; k++)
                    {
                        temp[l][k]=gamespace[l][k];
                    }
                };

                }

            }
        }
        if(m)
        {
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<6; j++)
                {
                    if(temp[i][j]>0)
                    {
                        continue;
                    }
                    else
                    {
                        *x=i;
                        *y=j;
                    }
                }
            }
        }
    }

    return;
}

int sum(int temp[8][6])
{

    int x=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(temp[i][j]>0)
            {
                x++;
            }
            else
            {
                continue;
            }
        }
    }
    return x;
}


int sum2(int temp[8][6])
{

    int x;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            x+=temp[i][j];
        }
    }
    return x;
}



bool winmove(int temp[8][6],int l,int m)
{

    int temp2[8][6];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp2[i][j]=temp[i][j];
        }
    }
    if(m<5){
temp2[l][m+1]++;
fission1(temp2,l,m+1);
if(terminationcondition(temp2)){return true;}
else{ for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp2[i][j]=temp[i][j];
        }
    }}
}
if(m>0){
temp2[l][m-1]++;
fission1(temp2,l,m-1);
if(terminationcondition(temp2)){return true;}
else{ for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp2[i][j]=temp[i][j];
        }
    }}}
if(l>0){
temp2[l-1][m]++;
fission1(temp2,l-1,m);
if(terminationcondition(temp2)){return true;}
else{ for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp2[i][j]=temp[i][j];
        }
    }}}
if(l<7){
temp2[l+1][m]++;
fission1(temp2,l,m+1);
if(terminationcondition(temp2)){return true;}
else{ for(int i=0; i<8; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp2[i][j]=temp[i][j];
        }
    }}}


    return false;
}




void highlight(int gamespace[8][6],int i,int j,int w)
{

    sf::RenderWindow *window;
    window = Window::getWindow();
    sf::Event event;
    if(!(i>7||i<0||j>5||j<0))
    {
        if(gamespace[i][j]==1)
        {
            sf::CircleShape circle(15);
            circle.setFillColor(sf::Color(200,0,0));
            circle.setPosition(65*j+110,65*i+90);
            window->draw(circle);
        }
        if(gamespace[i][j]==2)
        {
            sf::CircleShape circle(15);
            circle.setFillColor(sf::Color(200,0,0));
            circle.setPosition(65*j+120,65*i+90);
            window->draw(circle);
            sf::CircleShape circle1(15);
            circle1.setFillColor(sf::Color(200,0,0));
            circle1.setPosition(65*j+100,65*i+90);
            window->draw(circle1);

        }


        if(gamespace[i][j]==3)
        {
            sf::CircleShape circle(15);
            circle.setFillColor(sf::Color(200,0,0));
            circle.setPosition(65*j+120,65*i+90);
            window->draw(circle);
            sf::CircleShape circle1(15);
            circle1.setFillColor(sf::Color(200,0,0));
            circle1.setPosition(65*j+100,65*i+90);
            window->draw(circle1);
            sf::CircleShape circle2(15);
            circle2.setFillColor(sf::Color(200,0,0));
            circle2.setPosition(65*j+110,65*i+80);
            window->draw(circle2);
        }


        if(gamespace[i][j]==-1)
        {
            sf::CircleShape circle(15);
            circle.setFillColor(sf::Color(100, 250, 50));
            circle.setPosition(65*j+110,65*i+90);
            window->draw(circle);
        }

        if(gamespace[i][j]==-2)
        {
            sf::CircleShape circle(15);
            circle.setFillColor(sf::Color(100, 250, 50));
            circle.setPosition(65*j+120,65*i+90);
            window->draw(circle);
            sf::CircleShape circle1(15);
            circle1.setFillColor(sf::Color(100, 250, 50));
            circle1.setPosition(65*j+100,65*i+90);
            window->draw(circle1);
        }


        if(gamespace[i][j]==-3)
        {
            sf::CircleShape circle(15);
            circle.setFillColor(sf::Color(100, 250, 50));
            circle.setPosition(65*j+120,65*i+90);
            window->draw(circle);
            sf::CircleShape circle1(15);
            circle1.setFillColor(sf::Color(100, 250, 50));
            circle1.setPosition(65*j+100,65*i+90);
            window->draw(circle1);
            sf::CircleShape circle2(15);
            circle2.setFillColor(sf::Color(100, 250, 50));
            circle2.setPosition(65*j+110,65*i+80);
            window->draw(circle2);
        }
    }

    return;

}








