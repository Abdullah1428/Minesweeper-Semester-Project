#include "Normal.h"
#include <iostream>

#ifndef EASY_H
#define EASY_H

//For the difficulty of Easy
class Minesweeper_Easy : public Minesweeper_Normal
{
public:
    Minesweeper_Easy() : Minesweeper_Normal(9 , 10) {}
    /*
    Minesweeper_Normal::Minesweeper_Normal(const Minesweeper_Normal & a)
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
        Minesweeper_Normal::mine_planter();

    }
    void mine_indicator()
    {
        Minesweeper_Normal::mine_indicator();
    }
    int & Grid(int x , int y)
    {
        return Minesweeper_Normal::Grid(x,y);
    }
    int & Sgrid( int x , int y)
    {
        return Minesweeper_Normal::Sgrid(x,y);
    }
    int Size_Grid()
    {
        return Minesweeper_Normal::Size_Grid();
    }
    void emptyboxcheck(int a , int b)
    {
        Minesweeper_Normal::emptyboxcheck(a, b);
    }
    bool checkifwin()
    {
        Minesweeper_Normal::checkifwin();
    }
} ;

#endif


