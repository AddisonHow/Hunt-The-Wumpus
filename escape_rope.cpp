#include "escape_rope.hpp"
#include<string>
#include<iostream>
// TODO Escape rope implementation (define escape_rope member functions below)

void escapeRope::percept(){
    
}
void escapeRope::encounter(player&p, Room& rooms){
    
    if(p.getHasGold() == true){
        std::cout << "player escaped with gold" << std::endl;
        
    }
   else{
    std::cout <<  "player does not have gold and cant escape" << std::endl;
    
   }
    

}
std::string escapeRope::printName() const{
       
        return this->name;
   
    }
event* escapeRope::clone(){
    return new escapeRope;
}
