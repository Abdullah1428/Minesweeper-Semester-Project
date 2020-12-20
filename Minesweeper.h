
#ifndef MINESWEEPER_H
#define MINESWEEPER_H


// virtual class for the interface
class Minesweeper
{
public:
    virtual void mine_planter() = 0;
    virtual void mine_indicator() =0;
    virtual int & Grid(int x , int y) =0;
    virtual int & Sgrid( int x , int y) =0;
    virtual int Size_Grid()=0;
    virtual void emptyboxcheck(int a , int b)=0;
    virtual bool checkifwin()=0;
};

#endif
