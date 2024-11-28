#ifndef EVENT_HPP
#define EVENT_HPP
#include "player.hpp"

class Room;
// Event interface
class event {
private:
	
protected:
	// TODO protected members, if relevant
public:
	
	virtual std::string printName() const = 0;  // Pure virtual function to be overridden by derived classes
    virtual ~event() {}  // Virtual destructor

	virtual void percept() = 0;
	virtual void encounter(player& p, Room& thisRoom) = 0;
	virtual event* clone() = 0;

	
	// TODO public members
};

#endif
