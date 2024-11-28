#ifndef ARROW_HPP
#define ARROW_HPP
#include <iostream>
#include "event.hpp"
#include <string>
#include "room.hpp"
// TODO Arrow interface (define the arrow class and declare its member functions
// below)

class arrow : public event{
    private:
    std::string name = "A";

    public:
    //prints the percept message if player is in an adjacent room 
    void percept();
    void encounter(player& p,Room& room);
   
   
    std::string printName()const override{
       
        return this->name;
    }


event* clone();
};
#endif
