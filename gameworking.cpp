#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Minesweeper.h"
#include "Normal.h"
#include "Hard.h"
#include "Easy.h"
#include <iostream>
using namespace sf;

const int w=32; // width of the single box in picture

Minesweeper * GamePlay( Minesweeper * game);
int Menu();

int main()
{
        int difficulty;
        Minesweeper * game=NULL;

    while(1)
    {
        difficulty=Menu();

        if (difficulty==0)
            break;
        else if (difficulty==-1)
        {
            if (game==NULL)
                continue;
        }
        else if (difficulty==1)
        {
            game = new Minesweeper_Easy;
            game->mine_planter();
            game->mine_indicator();
        }
        else if (difficulty==2)
        {
            game = new Minesweeper_Normal;
            game->mine_planter();
            game->mine_indicator();
        }
        else if (difficulty==3)
        {
            game = new Minesweeper_Hard;
            game->mine_planter();
            game->mine_indicator();
        }
        game = GamePlay(game);
    }

    return 0;
}

int Menu()
{
    bool play=false , resume=false , exit=false;

    RenderWindow window(VideoMode(500, 500), "Minesweeper!",sf::Style::Titlebar | sf::Style::Close);
    Texture menu , menuplay , menuresume , menuexit;
    menu.loadFromFile("images/Menu.jpg");
    Sprite smenu(menu);

    menuplay.loadFromFile("images/Menu(play).jpg");
    Sprite smenuplay(menuplay);

    menuresume.loadFromFile("images/Menu(resume).jpg");
    Sprite smenuresume(menuresume);

    menuexit.loadFromFile("images/Menu(exit).jpg");
    Sprite smenuexit(menuexit);

    Texture difficulty, easy , normal , hard;
    difficulty.loadFromFile("images/difficulty.jpg");
    Sprite sdifficulty(difficulty);

    easy.loadFromFile("images/difficulty_easy.jpg");
    Sprite seasy(easy);

    normal.loadFromFile("images/difficulty_normal.jpg");
    Sprite snormal(normal);

    hard.loadFromFile("images/difficulty_hard.jpg");
    Sprite shard(hard);
	
	Music music; 
    music.openFromFile("data/FreeKO_Fame.ogg");
	music.setLoop(true);
	music.setRelativeToListener(true);
	music.setVolume(40.f);
	music.play();

    window.setFramerateLimit(15);

    while (window.isOpen()) 
    {
        Vector2i pos = Mouse::getPosition(window);
        // event processing 
        Event event;
        while (window.pollEvent(event))
        // event instances are filled by the poll event function of the
        // window class .
        {
        	// request for closing the window
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
                if (event.key.code==Mouse::Left && play!=true && resume!=true && exit != true)
                // event.mouseButton.button
            {
                if (pos.x>159 && pos.y>170 && pos.x<341 &&pos.y<218.67)
                    play=true;
                else if (pos.x>159 && pos.y>236 && pos.x<341 &&pos.y<285)
                    resume=true;
                else if (pos.x>159 && pos.y>304 && pos.x<341 &&pos.y<353)
                    exit=true;
            }
                else if (event.key.code==Mouse::Left)
                {
                    if (pos.x>159 && pos.y>170 && pos.x<341 &&pos.y<218.67)
                        return 1;
                    else if (pos.x>159 && pos.y>236 && pos.x<341 &&pos.y<285)
                        return 2;
                    else if (pos.x>159 && pos.y>304 && pos.x<341 &&pos.y<353)
                        return 3;
                }
            if (event.type==Event::KeyPressed)
                if (event.key.code==Keyboard::Escape && play==true )
            {
                play=false;
            }

        }

        window.clear();

        if (play!=true && resume!=true && exit != true) {
            if (pos.x>159 && pos.y>170 && pos.x<341 &&pos.y<218.67)
                window.draw(smenuplay);
            else if (pos.x>159 && pos.y>236 && pos.x<341 &&pos.y<285)
                window.draw(smenuresume);
            else if (pos.x>159 && pos.y>304 && pos.x<341 &&pos.y<353)
                window.draw(smenuexit);
            else
                window.draw(smenu);
        }
        else if (play==true)
        {
            if (pos.x>159 && pos.y>170 && pos.x<341 &&pos.y<218.67)
                window.draw(seasy);
            else if (pos.x>159 && pos.y>236 && pos.x<341 &&pos.y<285)
                window.draw(snormal);
            else if (pos.x>159 && pos.y>304 && pos.x<341 &&pos.y<353)
                window.draw(shard);
            else
                window.draw(sdifficulty);
        }
        else if (resume==true)
        {
            return -1;
        }
        else if (exit== true)
        {
            return 0;
        }

        window.display();
    }

    return 0;
}

Minesweeper * GamePlay( Minesweeper * game)
{
    RenderWindow win(VideoMode(game->Size_Grid()*32, game->Size_Grid()*32), "Minesweeper!",sf::Style::Titlebar | sf::Style::Close);

    Texture t , gamewin;
    t.loadFromFile("images/tiles.jpg");
    Sprite s(t);
    gamewin.loadFromFile("images/You-Win.png");
    Sprite sgamewin(gamewin);
    bool checkifwin=false;
 
 /*   
	Music music; 
    music.openFromFile("data/FreeKO_Fame.ogg");
	music.setLoop(true);
	music.setRelativeToListener(true);
	music.setVolume(40.f);
	music.play();
 */
    win.setFramerateLimit(15);

    while (win.isOpen())
    {
        Vector2i pos = Mouse::getPosition(win);
        int x = 50;
        int y = 50;

        Event e;
        while (win.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
            	win.close();
			}
                
                

   			if (e.type == Event::MouseButtonPressed)
            {
                x=pos.x/w;
                y=pos.y/w;
                std::cout<<"xcor "<<x<<" ycor "<<y<<std::endl;
                if (e.key.code == Mouse::Left)
                    {
                    	game->Sgrid(x,y)= game->Grid(x,y);
					}
					 // to show the value of neighbouring bombs around the 8 corners
                else if (e.key.code == Mouse::Right) {
                        game->Sgrid(x,y)=11;
                        checkifwin=game->checkifwin();
                        // when a user put flag we have to check 
                        // the whole box whether all the bombs are flaged or not
                }
            }
            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Escape)
                return game;
        }

        win.clear(Color::White);
       for (int i=0;i<game->Size_Grid();i++)
        for (int j=0;j<game->Size_Grid();j++)
          {
               if (x!=50 && game->Sgrid(x,y)==9) 
			   {
			   		game->Sgrid(i, j)=game->Grid(i , j);
			   	//	std::cout<<"new "<<i<<"new 2"<<j<<std::endl;
			   }
               else if (x!=50 && i==0 && j==0 && game->Sgrid(x,y)==0) 
			   {
			   		game->emptyboxcheck(x,y);
			   	//	std::cout<<"new 22 c "<<i<<"new 22 c"<<j<<std::endl;
			   }
               s.setTextureRect(IntRect(game->Sgrid(i , j)*w,0,w,w)); // the first two arguments are the top left co ordinates of the image u want to crop
               // last two are the height and length of the image in pixel ,,,in our case its 32
               s.setPosition(i*w, j*w);
               win.draw(s);
               if (checkifwin)
               {
                   sgamewin.setPosition( ((game->Size_Grid()*32)/2)-200, ((game->Size_Grid()*32)/2)-200);
                   win.draw(sgamewin);
               }
          }
        win.display();
    }
    return game;
}
