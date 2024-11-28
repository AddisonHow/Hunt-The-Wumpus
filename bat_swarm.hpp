#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP
#include "event.hpp"
#include <string>
#include "room.hpp"


class batSwarm : public event{

private:
    std::string name = "B"; 
    bool confuseMove;



public:
//prints the percept message if player is in an adjacent room 
    void percept();
    void encounter(player&p, Room& room);
    void confusePlayer();
   
    std::string printName()const override{
       
        return this->name;
    }
 
    
event* clone();
};
// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)


#endif
