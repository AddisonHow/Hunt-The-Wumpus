#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP
#include "event.hpp"
#include <iostream> 
#include <string> 
// TODO Bottomless Pit interface (define the bottomless_pit class and declare
// its member functions below)

class bottomlessPit : public event{

private:

std::string name = "P";
public:
//prints the percept message if player is in an adjacent room 
void percept();
/*
 * Function: encounter
 * Description: Simulates an encounter with a bottomless pit. The player has a 50% chance of dying 
 *              if they fall into the pit. If the player dies, their `isAlive` status is set to `false` 
 *              and a message is printed indicating their fate. If the player survives, no action is taken.
 * Parameters:
 * 		p (player&): A reference to the `player` object representing the player in the game.
 * 		rooms (Room&): A reference to the `Room` object that represents the room where the encounter occurs.
 * Returns: 
 * 		void: This function doesn't return a value but modifies the `player` object's state if the player dies.
 */
void encounter(player& p,Room& room);

  //void setName(std::string name){this->name = "B";}
std::string printName()const override{
        
return this->name;
    
}
event* clone();

};
#endif
