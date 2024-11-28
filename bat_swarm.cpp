#include "bat_swarm.hpp"
#include<string>
#include<iostream>

// TODO Bat Swarm implementation (define bat_swarm member functions below)


void batSwarm::percept(){
    std::cout << "you hear screeching" << std::endl;
}

void batSwarm::encounter(player&p, Room& rooms){
    
    p.setIsConfused(true);
    

}
event* batSwarm::clone(){
    return new batSwarm;
}
