//this is my new player class 
#include <iostream>
#include <string>



class player{

private:
    bool isAlive;
    bool isConfused;
    bool hasGold;
    int numArrows;
    int rowP;
    int colP;
public:
    player();
    player(bool isAlive, bool isConfused, bool hasGold, int numArrows);
    void setIsAlive(bool isAlive);//{this->isAlive = isAlive;}
    void setIsConfused(bool isConfused);//{this->isConfused = isConfused;}
    void setHasGold(bool hasGold);//{this->hasGold = hasGold;}
    void setNumArrows(int numArrows);//{this->numArrows = numArrows;}
    void setRowP(int rowP);//{this->rowP = rowP;}
    void setColP(int colP);//{this->colP = colP;}

    bool getIsAlive();//{return this->isAlive;}
    bool getIsConfused();//{return this->isConfused;}
    bool getHasGold();//{return this->hasGold;}
    int getNumArrows();//{return this->numArrows;}
    int getRowP();//{return this->rowP;}
    int getColP();//{return this->colP;}
    
};
