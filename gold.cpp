#include "gold.hpp"
#include <string>
#include <iostream>


void gold::percept(){
    std::cout << "you stub your toe on somehting heavy" << std::endl;
}
// TODO Gold implementation (define gold member functions below)

void gold::encounter(player&p, Room& room){
    //set p.gold to true, so they can escape 
   p.setHasGold(true);
    room.setRoomEvent(NULL);

}
event* gold::clone(){
    return new gold;
}
