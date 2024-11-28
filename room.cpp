#include "room.hpp"
#include<string>
#include<iostream>



// TODO Room implementation (define room member functions below)

Room::~Room(){
    delete this->roomEvent;
    this->roomEvent = nullptr;
}
Room::Room(const Room& otherRoom){
		if(roomEvent == nullptr){
			roomEvent = nullptr;
		}
		else{
		this->roomEvent = otherRoom.roomEvent->clone();
		}

	}
void  Room::operator=(const Room& otherRoom){
		if(this == &otherRoom){
			return;
		}
		delete[] this->roomEvent;
		if(otherRoom.roomEvent == nullptr){
			this->roomEvent = nullptr;
		}
		else{
			this->roomEvent = otherRoom.roomEvent->clone();
		}
	}	
