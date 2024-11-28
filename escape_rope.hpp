#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP
#include "event.hpp"
#include <iostream> 
#include <string> 
// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)

class escapeRope : public event{

private:

std::string name = "E";

public:
  void percept();
  /*
 * Function: encounter
 * Description: Simulates an encounter with an escape rope. If the player has gold, they are able 
 *              to escape and a message is displayed. If the player doesn't have gold, they are unable 
 *              to escape, and a message is displayed indicating this.
 * Parameters:
 * 		p (player&): A reference to the `player` object representing the player in the game.
 * 		rooms (Room&): A reference to the `Room` object where the encounter occurs.
 * Returns: 
 * 		void: This function doesn't return a value but prints messages based on whether the player 
 *              can escape or not.
 */
  void encounter(player& p,Room& room);
 // void setName(std::string name){this->name = "E";}
  std::string printName()const;


event* clone();

};
#endif
