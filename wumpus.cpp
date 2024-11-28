#include "wumpus.hpp"
#include<string>
#include<iostream>
// TODO Wumpus implementation (define wumpus member functions below)

void wumpus::percept(){
    std::cout << "the hairs stand up on the back of your neck" << std::endl;
}
void wumpus::encounter(player&p, Room& rooms){
    //kill player if wumpus is in the same room as player
    p.setIsAlive(false);
    

}

event* wumpus::clone(){
    return new wumpus;
}
