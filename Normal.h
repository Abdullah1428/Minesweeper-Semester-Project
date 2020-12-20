#include "hard.h"

#ifndef Normal_H
#define Normal_H

//For the difficulty of hard
class Minesweeper_Normal : public Minesweeper_Hard
{
public:
    Minesweeper_Normal() : Minesweeper_Hard(16 , 40) {} //40 mines
    Minesweeper_Normal(int gs , int m) : Minesweeper_Hard(gs , m) {}
    /*
    Minesweeper_Normal(const Minesweeper_Normal & a)
    {
        Grid_Size=a.Grid_Size;
        mines=a.mines;

            grid= new  int * [Grid_Size];
        for (int i=0 ; i<Grid_Size ; i++)
            grid[i] = new int [Grid_Size];
        sgrid= new int * [Grid_Size];
        for (int i=0 ; i<Grid_Size ; i++)
            sgrid[i] = new int [Grid_Size];

            for (int i=0 ; i<Grid_Size ; i++)
                for (int j=0 ; j<Grid_Size ; j++)
            {
                grid[i][j]=a.grid[i][j];
                sgrid[i][j]=a.sgrid[i][j];
            }
    }
    */
    void mine_planter()
    {
        Minesweeper_Hard::mine_planter();
    }
    void mine_indicator()
    {
        Minesweeper_Hard::mine_indicator();
    }
    int & Grid(int x , int y)
    {
        return Minesweeper_Hard::Grid(x,y);
    }
    int & Sgrid( int x , int y)
    {
        return Minesweeper_Hard::Sgrid(x,y);
    }
    int Size_Grid()
    {
        return Minesweeper_Hard::Size_Grid();
    }
    void emptyboxcheck(int a , int b)
    {
        Minesweeper_Hard::emptyboxcheck(a, b);
    }
    bool checkifwin()
    {
        Minesweeper_Hard::checkifwin();
    }
} ;

#endif

