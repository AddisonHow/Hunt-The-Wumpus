#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "event.hpp"
#include <iostream> 
#include <string> 
// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)


class wumpus : public event{

private:
std::string name = "W";
//bool wIsAlive = true;

public:
//prints the percept message if player is in an adjacent room 
  void percept();
  /*
 * Function: encounter
 * Description: Simulates an encounter with the Wumpus. If the player encounters the Wumpus, their 
 *              `isAlive` status is set to `false`, effectively killing the player.
 * Parameters:
 * 		p (player&): A reference to the `player` object representing the player who encounters the Wumpus.
 * 		rooms (Room&): A reference to the `Room` object where the encounter occurs.
 * Returns: 
 * 		void: This function doesn't return a value but modifies the `player` object's state, setting 
 *              `isAlive` to `false`.
 */
  void encounter(player& p,Room& room);
 
  std::string printName()const override{
     
      return this->name;
    }

  //bool getWIsAlive(){return this->wIsAlive;}
  //virtual void setWIsAlive(bool wIsAlive){this->wIsAlive = wIsAlive;}
 event* clone();
  
};
#endif
