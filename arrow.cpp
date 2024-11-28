#include "arrow.hpp"
#include<string>
#include<iostream>
// TODO Arrow implementation (define arrow member functions below)

void arrow::percept(){
    
}
void arrow::encounter(player& p,Room& room){
    int numA = p.getNumArrows();
    numA = numA + 1;
    p.setNumArrows(numA);
  //  std::cout << "num arrows" << p.getNumArrows() << std::endl;
    room.setRoomEvent(NULL);

}
event* arrow::clone(){
    return new arrow;
}
