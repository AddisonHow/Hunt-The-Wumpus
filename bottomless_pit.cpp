#include "bottomless_pit.hpp"
#include<string>
#include<iostream>


void bottomlessPit::percept(){
    std::cout << "you feel a breeze" << std::endl;
}
// TODO Bottomless Pit implementation (define bottomless_pit member functions
// below)
void bottomlessPit::encounter(player&p, Room& rooms){
    srand(static_cast<unsigned>(time(0)));
	
		

		int chanceDeath = rand() % 2;
   if(chanceDeath == 1){
    p.setIsAlive(false); 
    std::cout << "you fell a long way down, and your still falling..." << std::endl;
   }
   else{
    
   }
   
}
event* bottomlessPit::clone(){
    return new bottomlessPit;
}
