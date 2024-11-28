#ifndef GOLD_HPP
#define GOLD_HPP
#include "event.hpp"
#include <iostream> 
#include <string> 
#include "room.hpp"
// TODO Gold interface (define the gold class and declare its member functions
// below)
class gold : public event{

private:
std::string name = "G";

public: 
//prints the percept message if player is in an adjacent room 
  void percept();
  /*
 * Function: encounter
 * Description: Simulates an encounter with gold. When the player encounters the gold, the player's 
 *              `hasGold` status is set to `true`, indicating they have obtained the gold. Additionally, 
 *              the event in the room is cleared (set to `NULL`), as the gold has been collected.
 * Parameters:
 * 		p (player&): A reference to the `player` object representing the player who encounters the gold.
 * 		room (Room&): A reference to the `Room` object where the encounter occurs.
 * Returns: 
 * 		void: This function doesn't return a value but modifies the `player` object's state and the 
 *              event in the room.
 */
  void encounter(player& p,Room& room);
   
    std::string printName()const override{
       
        return this->name;
    }

    event* clone();
};

#endif
