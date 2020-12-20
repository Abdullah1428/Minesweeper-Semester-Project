#include "Minesweeper.h"


#ifndef HARD_H
#define HARD_H

//For the difficulty of hard
class Minesweeper_Hard : public Minesweeper
{
private:
    int Grid_Size;
    int **grid;
    int **sgrid;
    int mines;
public:
    Minesweeper_Hard();
    Minesweeper_Hard(int gs , int m);
    ~Minesweeper_Hard();
    //Minesweeper_Hard(const Minesweeper_Hard & a);
    void mine_planter();
    void mine_indicator();
    int & Grid(int x , int y);
    int & Sgrid( int x , int y);
    int Size_Grid();
    void emptyboxcheck(int a , int b);
    bool checkifwin();
} ;

#endif
