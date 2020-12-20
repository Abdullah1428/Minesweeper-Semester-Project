#include "Hard.h"
#include <time.h>   // for time()
#include <stdlib.h> // for srand()
#include <iostream>

Minesweeper_Hard::Minesweeper_Hard() : Grid_Size(22) , mines (99)
{
    grid= new  int * [Grid_Size];
    for (int i=0 ; i<Grid_Size ; i++)
        grid[i] = new int [Grid_Size];
    sgrid= new int * [Grid_Size];
    for (int i=0 ; i<Grid_Size ; i++)
        sgrid[i] = new int [Grid_Size];
}

Minesweeper_Hard::Minesweeper_Hard(int gs , int m) : Grid_Size(gs) , mines (m)
{
    grid= new  int * [Grid_Size];
    for (int i=0 ; i<Grid_Size ; i++)
        grid[i] = new int [Grid_Size];
    sgrid= new int * [Grid_Size];
    for (int i=0 ; i<Grid_Size ; i++)
        sgrid[i] = new int [Grid_Size];
}

/*
Minesweeper_Hard::Minesweeper_Hard(const Minesweeper_Hard & a)
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

Minesweeper_Hard::~Minesweeper_Hard()
{
    for (int i = 0; i <Grid_Size; i++) {
        delete [] grid[i];
                    }
        delete [] grid;
    for (int i = 0; i <Grid_Size; i++) {
        delete [] sgrid[i];
                    }
        delete [] sgrid;
}

void Minesweeper_Hard::mine_planter()
{
    srand(time(0));

    for (int i=0 ; i<Grid_Size ; i++)
        for (int j=0 ; j<Grid_Size ; j++)
    {
        sgrid[i][j]=10;
        grid[i][j]=0;
    }

    for (int i=0 ; i<mines ; i++) // 10 bombs will be planted
    {
        int x, y;   // to avoid planting bombs at the same position
        x=rand()%Grid_Size;
        y=rand()%Grid_Size;
        if (grid[x][y]!=9)
            grid[x][y]=9;
        else  // to cancel the iteration in which rand function generate the same co-ordinates for the bomb plantation
            i--;
    }
}

void Minesweeper_Hard::mine_indicator()
{
    for (int i=0;i<Grid_Size;i++)
     for (int j=0;j<Grid_Size;j++)
      {
        int n=0;
        if (grid[i][j]==9) continue;
        if (i+1 < Grid_Size && grid[i+1][j]==9) n++; //right side
        if (j+1 < Grid_Size && grid[i][j+1]==9) n++; // down side
        if (i-1 >=0 && grid[i-1][j]==9) n++; // left side
        if (j-1 >=0 && grid[i][j-1]==9) n++; // upper side
        if (i+1 < Grid_Size && j+1 < Grid_Size && grid[i+1][j+1]==9) n++; // last element in a 3*3
        if (i-1 >=0 && j-1 >=0 && grid[i-1][j-1]==9) n++; // first element in 3*3
        if (j+1 < Grid_Size && i-1 >=0 && grid[i-1][j+1]==9) n++; // third element in a 3*3
        if (i+1 < Grid_Size && j-1 >=0 && grid[i+1][j-1]==9) n++; // 7 element in a 3*3
        grid[i][j]=n;
      }
}

int & Minesweeper_Hard::Grid(int x , int y)
{
    if (x>=0 && x<Grid_Size && y>=0 && y<Grid_Size)
        return grid[x][y];
}

int & Minesweeper_Hard::Sgrid(int x , int y)
{
    if (x>=0 && x<Grid_Size && y>=0 && y<Grid_Size)
        return sgrid[x][y];
}
int Minesweeper_Hard::Size_Grid()
{
    return Grid_Size;
}

void Minesweeper_Hard::emptyboxcheck(int a , int b)
{
        static int xcor[500];
        static int ycor[500];
        static int k=0;
        static int i=0;
        if (i==0)
        {
                for (int i=0 ; i<500 ; i++)
                {
                    xcor[i]=99;
                    ycor[i]=99;
                }
        }
        static int s=Grid_Size;
            if (a-1>=0) {  //  left side
                    if (grid[a-1][b]==0 && sgrid[a-1][b]!=0) {
                    sgrid[a-1][b]=0;
                    k++;
                    xcor[k]=a-1;
                    ycor[k]=b;
                    }
                    else if (sgrid[a-1][b]!=0)
                    {
                            sgrid[a-1][b]=grid[a-1][b];
                    }
            }
            if (b+1<s) {   // downside
                    if (grid[a][b+1]==0 && sgrid[a][b+1]!=0) {
                    sgrid[a][b+1]=0;
                    k++;
                    xcor[k]=a;
                    ycor[k]=b+1;
                    }
                    else if (sgrid[a][b+1]!=0)
                    {
                            sgrid[a][b+1]=grid[a][b+1];
                    }
            }
            if (b-1>=0 ) {  // upper side
                if (grid[a][b-1]==0 && sgrid[a][b-1]!=0) {
                    sgrid[a][b-1]=0;
                    k++;
                    xcor[k]=a;
                    ycor[k]=b-1;
                }
                else if (sgrid[a][b-1]!=0)
                    {
                            sgrid[a][b-1]=grid[a][b-1];
                    }
            }
            if (a+1<s) { // right side
                if (grid[a+1][b]==0 && sgrid[a+1][b]!=0) {
                    sgrid[a+1][b]=0;
                    k++;
                    xcor[k]=a+1;
                    ycor[k]=b;
                }
                else if (sgrid[a+1][b]!=0)
                    {
                            sgrid[a+1][b]=grid[a+1][b];
                    }
            }
            if (a+1<s && b-1>=0 ) {  // 3 element in 3*3 
                if (grid[a+1][b-1]==0 && sgrid[a+1][b-1]!=0) {
                    sgrid[a+1][b-1]=0;
                    k++;
                    xcor[k]=a+1;
                    ycor[k]=b-1;
                }
                else if (sgrid[a+1][b-1]!=0) 
                    {
                            sgrid[a+1][b-1]=grid[a+1][b-1];
                    }
            }
            if (a+1<s && b+1<s ) {   // last element in 3*3
                if (grid[a+1][b+1]==0 && sgrid[a+1][b+1]!=0) {
                    sgrid[a+1][b+1]=' ';
                    k++;
                    xcor[k]=a+1;
                    ycor[k]=b+1;
                }
                else if (sgrid[a+1][b+1]!=0)
                    {
                            sgrid[a+1][b+1]=grid[a+1][b+1];
                    }
            }
            if (a-1>=0 && b-1>=0) {  //  1 element in 3*3
                if (grid[a-1][b-1]==0 && sgrid[a-1][b-1]!=0) {
                    sgrid[a-1][b-1]=' ';
                    k++;
                    xcor[k]=a-1;
                    ycor[k]=b-1;
                }
                else if (sgrid[a-1][b-1]!=0)
                    {
                            sgrid[a-1][b-1]=grid[a-1][b-1];
                    }
            }
            if (a-1>=0 && b+1<s) {  // 5 element in 3*3
                if (grid[a-1][b+1]==0 &&  sgrid[a-1][b+1]!=0) {
                    sgrid[a-1][b+1]=0;
                    k++;
                    xcor[k]=a-1;
                    ycor[k]=b+1;
                }
                else if (sgrid[a-1][b+1]!=0)
                    {
                            sgrid[a-1][b+1]=grid[a-1][b+1];
                    }
            }

            i++;
            if (xcor[i]!=99 || ycor[i]!=99) {
                emptyboxcheck(xcor[i],ycor[i]);
            }
            else
            {
                i=0;
                k=0;
            }
}

bool Minesweeper_Hard::checkifwin()
{
    int cnt=0;
    for (int i=0 ; i<Grid_Size ; i++)
        for (int j=0 ; j<Grid_Size ; j++)
    {
        if (sgrid[i][j]==11 && grid[i][j]==9)
            cnt++;
    }
    return ( (cnt==mines) ? true : false);
}
