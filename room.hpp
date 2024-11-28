#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include "event.hpp"
#include<string>

// Room interface
class Room {
private: 
	event* roomEvent = NULL;
	std::string name;
	// TODO private members
public:
	event* getEvent()const{return this->roomEvent;}
	Room() = default; 
void setRoomEvent(event* roomEvent){
if(this->roomEvent != NULL){
	delete this->roomEvent;
	
}
 this->roomEvent = roomEvent;
}


~Room();

	 Room(const Room& otherRoom);

	void operator=(const Room& otherRoom);/
};



#endif
