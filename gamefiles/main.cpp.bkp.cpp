#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace std;

int criticalmass(int i,int j);

void fission1(int gamespace[8][6],int i, int j);
void fission2(int gamespace[8][6],int i, int j);
bool terminationcondition(int gamespace[8][6]);
int main()
{
int w=0;int x;int y;int a;int b;bool m=false;
	int gamespace[8][6];//grid of the game
	for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{
			gamespace[i][j]=0;
		}
	}


    // create the window

    sf::RenderWindow window(sf::VideoMode(800, 600), "Chain Reaction");


    // run the program as long as the window is open
    while (window.isOpen())
    {int p1count=0;int p2count=0;
window.setVerticalSyncEnabled(true);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Texture texture;
        sf::Sprite sprite;

while (window.pollEvent(event))
{
            // "close requested" event: we close the window
    if (event.type == sf::Event::Closed)
                {window.close();}

    if(event.type == sf::Event::KeyPressed&&(w==4)){
                         if (event.key.code == sf::Keyboard::Escape||event.key.code == sf::Keyboard::BackSpace){w=1;}}

              if(event.type == sf::Event::KeyPressed&&(w==0))  {w=1;


                }
    if (event.type == sf::Event::MouseButtonPressed)
     {
        if (event.mouseButton.button == sf::Mouse::Left&&(w==1))
        {
        x=event.mouseButton.x-218;
        y=event.mouseButton.y ;
        if(x>290&&y>340&&x<490&&y<375){w=2;}
        if(x>290&&y>400&&x<490&&y<440){w=3;window.clear();}
        if(x>290&&y>455&&x<490&&y<490){w=4;}

        if(x>290&&y>530&&x<490&&y<550){window.close();}
        }

     }

}



if(w==1){window.clear();
                    texture.loadFromFile("4.1.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);}
if(w==4){window.clear();
                    texture.loadFromFile("credits.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);
                        }

 if(w==0){window.clear();
                    texture.loadFromFile("3.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);
                        sf::Font font;

                        sf::Text text;
                        font.loadFromFile("Button T Italic.ttf");
                        // select the font
                        text.setFont(font); // font is a sf::Font

                        // set the string to display
                        text.setString("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                       Welcome to the world of gaming\n                       Press any key to continue");

                        // set the character size
                        text.setCharacterSize(24); // in pixels, not points!

                        // set the color
                        text.setColor(sf::Color::Green);

                        // set the text style
                        text.setStyle(sf::Text::Bold );



                        // inside the main loop, between window.clear() and window.display()
                        window.draw(text);}

if(w==3){  texture.loadFromFile("p1grid.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);

                        for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{
			if(gamespace[i][j]==1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);}


           if(gamespace[i][j]==3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(150, 50, 250));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}



			if(gamespace[i][j]==-1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==-2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }

           if(gamespace[i][j]==-3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(100, 250, 50));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}

        }
    }

  if (event.type == sf::Event::MouseButtonPressed){

  if (event.mouseButton.button == sf::Mouse::Left&&(w==3))
         {p1count++;
         if(p1count>0)
           {
               x=event.mouseButton.x;
           y=event.mouseButton.y;
           a=(y-75)/65;b=(x-100)/65;
           if(a>=0&&b>=0&&a<8&&b<6){
                if(gamespace[a][b]>=0)
                {gamespace[a][b]++;fission1(gamespace,a,b);
    // the main thread continues to run...


           for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{

			if(gamespace[i][j]==1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);}


           if(gamespace[i][j]==3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(150, 50, 250));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}

        }
		};
		w=5;if(m){if(terminationcondition(gamespace)){sf::sleep(sf::milliseconds(1000));w=6 ;
                                                     }}m=true;
	}}
           }

         }
  }

       }

if(w==5){window.clear();
        texture.loadFromFile("p2grid.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);

                        for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{

			if(gamespace[i][j]==1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}
           if(gamespace[i][j]==2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }


           if(gamespace[i][j]==3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(150, 50, 250));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}


			if(gamespace[i][j]==-1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==-2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }


            if(gamespace[i][j]==-3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(100, 250, 50));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}
        }
    }
if (event.type == sf::Event::MouseButtonPressed){

  if (event.mouseButton.button == sf::Mouse::Right&&(w==5))
         {p2count++;
         if(p2count>0){
               x=event.mouseButton.x;
           y=event.mouseButton.y;
           a=(y-75)/65;b=(x-100)/65;
           if(a>=0&&b>=0&&a<8&&b<6){
                if(gamespace[a][b]<=0)
               {
                gamespace[a][b]--;fission2(gamespace,a,b);
           for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{
			if(gamespace[i][j]==-1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}
           if(gamespace[i][j]==-2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }
             if(gamespace[i][j]==-3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(100, 250, 50));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}
        }
		};
		w=3;if(terminationcondition(gamespace)){sf::sleep(sf::milliseconds(1000)); w=7;
                                                             }
	}}


         }}}



}
if(w==6){
window.clear();


		                                              texture.loadFromFile("p1w.jpg");
                                                            sprite.setTexture(texture);
                                                            // inside the main loop, between window.clear() and window.display()
                                                            window.draw(sprite);
                                                            texture.setSmooth(true);
                                                           }


if(w==7){window.clear();


		                                              texture.loadFromFile("p2w.jpg");
                                                            sprite.setTexture(texture);
                                                            // inside the main loop, between window.clear() and window.display()
                                                            window.draw(sprite);
                                                            texture.setSmooth(true);
                                                          }

if(w==2){window.clear();

    texture.loadFromFile("pgrid.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);

    for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{ for(int j=0;j<6;j++)
		{
			if(gamespace[i][j]==1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);}


           if(gamespace[i][j]==3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(150, 50, 250));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}



			if(gamespace[i][j]==-1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==-2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }

           if(gamespace[i][j]==-3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(100, 250, 50));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}

        }
    }

  if (event.type == sf::Event::MouseButtonPressed){

  if (event.mouseButton.button == sf::Mouse::Left&&(w==2))
         {p1count++;
         if(p1count>0)
           {x=event.mouseButton.x;
           y=event.mouseButton.y;
           a=(y-75)/65;b=(x-100)/65;
           if(a>=0&&b>=0&&a<8&&b<6){
                if(gamespace[a][b]>=0)
                {gamespace[a][b]++;fission1(gamespace,a,b);
    // the main thread continues to run...


           for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{

			if(gamespace[i][j]==1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);}


           if(gamespace[i][j]==3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(150, 50, 250));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}

        }
		};
		w=8;if(m){if(terminationcondition(gamespace)){w=9 ;


                                                     }}m=true;
	}}
           }

         }
  }

       }





if(w==8){

    window.clear();
        texture.loadFromFile("sgrid.jpg");


                        sprite.setTexture(texture);

                        // inside the main loop, between window.clear() and window.display()
                        window.draw(sprite);
                        texture.setSmooth(true);

                        for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{

			if(gamespace[i][j]==1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}
           if(gamespace[i][j]==2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }


           if(gamespace[i][j]==3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(150, 50, 250));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(150, 50, 250));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}


			if(gamespace[i][j]==-1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}

           if(gamespace[i][j]==-2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }


            if(gamespace[i][j]==-3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(100, 250, 50));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}
        }

    }


  if (w==8)
         {p2count++;
         if(p2count>0){
             cout<<"input i and j"<<endl;window.display();
             cin>>a>>b;
           if(a>=0&&b>=0&&a<8&&b<6){
                if(gamespace[a][b]<=0)
               {
                gamespace[a-1][b-1]--;fission2(gamespace,a-1,b-1);
           for(int i=0;i<8;i++)//initialise the all the array elements  to zero
	{
		for(int j=0;j<6;j++)
		{
			if(gamespace[i][j]==-1){ sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+110,65*i+90);
           window.draw(circle);}
           if(gamespace[i][j]==-2){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+90);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(150, 50, 250));
           circle1.setPosition(65*j+100,65*i+90);
           window.draw(circle1);
                                 }
             if(gamespace[i][j]==-3){
                    sf::CircleShape circle(15);
           circle.setFillColor(sf::Color(100, 250, 50));
           circle.setPosition(65*j+120,65*i+80);
           window.draw(circle);
           sf::CircleShape circle1(15);
           circle1.setFillColor(sf::Color(100, 250, 50));
           circle1.setPosition(65*j+100,65*i+80);
           window.draw(circle1);
           sf::CircleShape circle2(15);
           circle2.setFillColor(sf::Color(100, 250, 50));
           circle2.setPosition(65*j+110,65*i+90);
           window.draw(circle2);}
        }
		};
		w=2;if(terminationcondition(gamespace)){ w=10;
                                                             }
	}}


         }}



}




if(w==9){
window.clear();


		                                              texture.loadFromFile("uwin.jpg");
                                                            sprite.setTexture(texture);
                                                            // inside the main loop, between window.clear() and window.display()
                                                            window.draw(sprite);
                                                            texture.setSmooth(true);
                                                           }


if(w==10){
window.clear();


		                                              texture.loadFromFile("ulost.jpg");
                                                            sprite.setTexture(texture);
                                                            // inside the main loop, between window.clear() and window.display()
                                                            window.draw(sprite);
                                                            texture.setSmooth(true);
                                                           }





        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}


void fission1(int gamespace[8][6],int i, int j)
{
	if(i<0||i>7||j<0||j>5||gamespace[i][j]<criticalmass(i,j))//fission occurs only inside the grid and ends when it does not exceed critical mass
	{
		return;
	}
	else{
	gamespace[i][j]=0;//the orb explodes if it exceeds critical mass
       if(j<5){
        if(gamespace[i][j+1]<0)

    {

		gamespace[i][j+1]=(-(gamespace[i][j+1]))+1;//if they hit orbs of other colour they change its colour
	}
	else
	{
		gamespace[i][j+1]++;//if they hit orbs of same colour they increase in mass
	}}
	//this  recursion occurs until the fission terminates
	 if(i<7){
		if(gamespace[i+1][j]<0)
	{
		gamespace[i+1][j]=(-(gamespace[i+1][j]))+1;//if they hit orbs of other colour they change its colour
	}
	else
	{
		gamespace[i+1][j]++;//if they hit orbs of same colour they increase in mass
	}}
	//this  recursion occurs until the fission terminates
 if(j>0){
		if(gamespace[i][j-1]<0)
    {
 gamespace[i][j-1]=(-(gamespace[i][j-1]))+1;//if they hit orbs of other colour they change its colour
    }
	else
	{
		gamespace[i][j-1]++;//if they hit orbs of same colour they increase in mass
	}}
	//this  recursion occurs until the fission terminates

 if(i>0){
		if(gamespace[i-1][j]<0)
	{
		gamespace[i-1][j]=(-(gamespace[i-1][j]))+1;//if they hit orbs of other colour they change its colour
	}
	else
	{
		gamespace[i-1][j]++;//if they hit orbs of same colour they increase in mass
	}}


 if(j<5){
	fission1(gamespace,i,j+1);}
 if(i<7){
	fission1(gamespace,i+1,j);}
	 if(i>0){
	fission1(gamespace,i-1,j);}
	if(j>0){//this  recursion occurs until the fission terminates
    fission1(gamespace,i,j-1);}
	return;}
}


void fission2(int gamespace[8][6],int i, int j)
{
	if(i<0||i>7||j<0||j>5||-gamespace[i][j]<criticalmass(i,j))
	{
		return;
	}
	else{
	gamespace[i][j]=0;
	 if(j<5){
	if(gamespace[i][j+1]>0)
	{
		gamespace[i][j+1]=(-(gamespace[i][j+1]))-1;
	}
	else
	{
		gamespace[i][j+1]--;
	}}
if(i<7){
		if(gamespace[i+1][j]>0)
	{
		gamespace[i+1][j]=(-(gamespace[i+1][j]))-1;
	}
	else
	{
		gamespace[i+1][j]--;
	}}
 if(j>0){

		if(gamespace[i][j-1]>0)
	{
		gamespace[i][j-1]=(-(gamespace[i][j-1]))-1;
	}
	else
	{
		gamespace[i][j-1]--;
	}}

if(i>0){
		if(gamespace[i-1][j]>0)
	{
		gamespace[i-1][j]=(-(gamespace[i-1][j]))-1;
	}
	else
	{
		gamespace[i-1][j]--;
	}}

 if(j<5){
	fission2(gamespace,i,j+1);}
	if(i<7){
	fission2(gamespace,i+1,j);}
	if(i>0){
	fission2(gamespace,i-1,j);}
	if(j>0){
	fission2(gamespace,i,j-1);}
	return;}
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
	int i,j;int k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(gamespace[i][j]>=0)
			{
				k++;
			}
		}

	}
	if(k==48){return true;}
	 k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(gamespace[i][j]<=0)
			{
				k++;
			}
		}

	}
	if(k==48){return true;}

	return false;

}
