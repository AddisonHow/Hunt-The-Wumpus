#include <iostream>
#include <vector>
#include "game.hpp"
//#include <ctime>
//#include <cstdlib>
//#include <cmath>

// game implementation

game::game(int width, int height, bool debug,player& p):
		width(width),
		height(height),
		debug(debug) {
	// TODO Create the game board: 2D vector of room objects
	for(int i = 0; i < height; i++){
		std::vector<Room> rows;
		/*for(int j = 0; j < width; j++){
			cols.push_back(Room());
		}*/
		rows.resize(width);
		this->rooms.push_back(rows);
	}	
	

	std::vector<event*> eventArr = {new batSwarm, new batSwarm, new bottomlessPit, new bottomlessPit, new wumpus, new gold, new arrow, new arrow, new escapeRope};
	srand(static_cast<unsigned>(time(0)));
	for(int i = 0; i < 9; i++){
		int insertcols = rand() % width;
		int insertrows = rand() % height;
		while(rooms[insertrows][insertcols].getEvent() != NULL){ //executes if there is an event in the room
			insertcols = rand() % width;
			insertrows = rand() % height;
		}
		
		rooms[insertrows][insertcols].setRoomEvent(eventArr[i]);
		
		if(i == 8){
			p.setRowP(insertrows);
			
			p.setColP(insertcols);
			
		}
		if(i == 4){
			setWCol(insertcols);
			setWRow(insertrows);
		}
	}
	/*
	for(int i = 0; i < height; i++){
		for(int j; j < width; j++){
	std::cout << rooms[i][j].getEvent().printName() << std::endl;
		}
	}*/
 	// TODO Randomly insert events (2 bat_swarms, 2 bottomless_pits,
	// 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board
}


void game::display_game(player& p) const{
	std::cout << std::endl << std::endl;
	std::cout << "Arrows remaining: " << p.getNumArrows() << std::endl;

	std::string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	std::cout << row_border << std::endl;
	for (int i = 0; i < this->height; ++i) {
		std::cout << "||";
		for (int j = 0; j < this->width; ++j) {
			
			if(p.getRowP() == i && p.getColP() == j){
				std::cout << "*";
			}
		
			if(this->debug){
				if(rooms[i][j].getEvent() == NULL){
					std::cout << " ";
				}
				else if(rooms[i][j].getEvent() != NULL){
				std::cout << rooms[i][j].getEvent()->printName();
				
				}

			}
			

			std::cout << " ||";
		}
		std::cout << std::endl;
		std::cout << row_border << std::endl;
	}


}

bool game::check_win(player& p) const{
	//check to see if wumpus is alive, and if so print statment and end game 
	if(getWumpusAlive() == false){
		std::cout << "you kileed the wumpus and survived" << std::endl;
		return true;
	}
	//check to see if player made it to escape rope with gold and if so print statment and end game
	else if(rooms[p.getRowP()][p.getColP()].getEvent() != NULL && this->rooms[p.getRowP()][p.getColP()].getEvent()->printName() == "E" && p.getHasGold() == true){
		std::cout << "you escaped the cave with the gold" << std::endl;
		return true;
	}
	else{
		return false;
	}

	
	
}

bool game::check_lose(player& p) const{

//run check to see if player is alive and if not alive print statment and end game
	if(p.getIsAlive() == false){
		std::cout << "you died, better luck next time " << std::endl; 
		return true;
	}
	else{
	return false;
	}

	
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction, player& p) {
//run check for if player wants to move down
if(direction == 's' && p.getRowP() + 1 >= height){
	
	return false;
}	
//run check for if player wants to move up 
else if(direction == 'w' &&  p.getRowP() - 1 < 0){
	return false;
}
//run check for check if room to the right of player has an event
else if(direction == 'd' && p.getColP() + 1 >= width){
	return false ;
	
}
//check if room to the left of player has an event
else if(direction == 'a' && p.getColP() - 1 < 0){
	return false;
	

}
else{
	return true;
}
	
	
	
}

bool game::is_valid_action(char action, player& p) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction, p);
	} else if (action == 'f') {
		return p.getNumArrows() > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		std::cout << "You can't move in that direction!" << std::endl <<
			std::endl;
	} else if (action == 'f') {
		std::cout << "You're out of arrows!" << std::endl << std::endl;
	} else {
		std::cout << std::endl << "That's an invalid input!" << std::endl
			<< std::endl;
	}
}

char game::get_player_action(player& p) {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << std::endl << std::endl << "What would you like to do?" <<
			std::endl << std::endl;
		std::cout << "w: move up" << std::endl;
		std::cout << "a: move left" << std::endl;
		std::cout << "s: move down" << std::endl;
		std::cout << "d: move right" << std::endl;
		std::cout << "f: fire an arrow" << std::endl;

		std::cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action,p));

	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "That's an invalid input!" <<
				std::endl << std::endl;
		}
		first = false;

		std::cout << std::endl << std::endl <<
			"What direction would you like to fire the arrow?" << std::endl <<
			std::endl;
		std::cout << "w: up" << std::endl;
		std::cout << "a: left" << std::endl;
		std::cout << "s: down" << std::endl;
		std::cout << "d: right" << std::endl;

		std::cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

void game::move_up(player& p) {
	//set the players row to one less than current row for moving up
	int pRow = p.getRowP(); 
	pRow = pRow - 1;
	
    p.setRowP(pRow);
	
	
}

void game::move_down(player& p) {
	//set players row to one more that current row for if they are moving down 
	int pRow = p.getRowP(); 
	pRow = pRow + 1;
	
	
    p.setRowP(pRow);
	
	
}

void game::move_left(player& p) {
	//set players col to one less than current col if they want to move left 
	int pCol = p.getColP();
	pCol = pCol - 1;
	p.setColP(pCol);
	
}

void game::move_right(player& p) {
//set players col to one more than current col if they want to move right
int pCol = p.getColP();
	pCol = pCol + 1;
	p.setColP(pCol);
	
}
//	MAKE THIS INTO A DO WHILE LOOP TO FIX SEG FAULT
//if bat is on the top row seg faults occur, so just make a do while loop that keeps randomizing untill a valid direction is picked with the rand function
void game::move(char direction, player& p) {
	//if player is confused 
	if(p.getIsConfused()){
		// confuse player
		srand(static_cast<unsigned>(time(0)));
	//gets a random num between 0-3 and assign that num to a direction
	do{
		int confuse = rand() % 4;
		//check to make sure that that random direction is valid(so they wont attempt to go out of bounds)
		if(confuse == 1 && p.getRowP() + 1 < height){
			direction = 's';
		}
		else if(confuse == 2 && p.getRowP() - 1 >= 0){
			direction = 'w';
		}
		else if(confuse == 3 && p.getColP() + 1 < width){
			direction = 'd';
		}
		else if(confuse == 0 && p.getColP() - 1 >= 0){
			direction = 'a';
		}
		else{
			//else is to make sure that the while loop will run untill a valid direction is found, like if they player is confused by a wall on the right, so they cant go out of bounds
			direction = 'x';
		}
		}while(direction == 'x');
	}
		if (direction == 'w') {
			this->move_up(p);
		} else if (direction == 'a') {
			this->move_left(p);
		} else if (direction == 'd') {
			this->move_right(p);
		} else {
			this->move_down(p);
		}
	p.setIsConfused(false);
}

void game::fire_arrow_up(player& p) {
	// TODO Delete the below placeholder code. Fire the arrow upward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	for(int i = 1; i < 4; i++){
		if(p.getRowP() - i >= 0 && this->rooms[p.getRowP() - i][p.getColP()].getEvent() != NULL && this->rooms[p.getRowP() - i][p.getColP()].getEvent()->printName() == "W" ){
			
			setWumpusIsAlive(false);
		}
		else{
		
		}
	}	
	
}

void game::fire_arrow_down(player&p, int height) {
	for(int i = 1; i < 4; i++){
		if(p.getRowP() + i < height-1 && this->rooms[p.getRowP() + i][p.getColP()].getEvent() != NULL && this->rooms[p.getRowP() + i][p.getColP()].getEvent()->printName() == "W" ){
		
			setWumpusIsAlive(false);
			
		}
		else{
			
		}
	}	
	
	
}

void game::fire_arrow_left(player& p) {
	// TODO Delete the below placeholder code. Fire the arrow leftward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	for(int i = 1; i < 4; i++){
		if(p.getColP() - i >= 0 && this->rooms[p.getRowP()][p.getColP()- i].getEvent() != NULL && this->rooms[p.getRowP()][p.getColP() - i].getEvent()->printName() == "W" ){
			//arrow hit wumpus so its dead
			setWumpusIsAlive(false);
				
			
		}
		else{
		
		}
	}	
	
}

void game::fire_arrow_right(player& p, int width) {
	
	// the wumpus if it hits it or making the wumpus "wake up" and move
// randomly if it misses
for(int i = 1; i < 4; i++){
	if(p.getColP() + i < width - 1 && this->rooms[p.getRowP()][p.getColP() + i].getEvent() != NULL && this->rooms[p.getRowP()][p.getColP() + i].getEvent()->printName() == "W" ){
		setWumpusIsAlive(false);	
	}
	else{
		
	}
}	
}

void game::fire_arrow(char direction,player& p) {
	if (direction == 'w') {
		this->fire_arrow_up(p);
	} else if (direction == 'a') {
		this->fire_arrow_left(p);
	} else if (direction == 'd') {
		this->fire_arrow_right(p,width);
	} else {
		this->fire_arrow_down(p,height);
	}
	if(getWumpusAlive() == true){
	moveWumpus();
}
	p.setNumArrows(p.getNumArrows()-1);
}

void game::play_game(player& p){
while (!this->check_win(p) && !this->check_lose(p)) {
		// Print game board
	this->display_game(p);

		
	printPercept(p,height,width);
		// Ask player for their action
		
	char action = this->get_player_action(p);
		

		// Process action
	if (this->is_direction(action)) {
			// W/A/S/D = move player
		char direction = action;
			//added player reference
		this->move(direction,p);
	} else {
			// F = prompt for arrow fire direction and fire arrow
		char direction = this->get_arrow_fire_direction();
		this->fire_arrow(direction,p);
	}

		// TODO If the user is on a space with an event, trigger its encounter
	Room& thisRoom = rooms[p.getRowP()][p.getColP()];
		if(thisRoom.getEvent() != NULL){
			thisRoom.getEvent()->encounter(p,thisRoom);
		}

		
	}
}

void game::printPercept(player& p, int height, int width){
	//check if room bellow player has a event
	int checkH = height - 1;

if((p.getRowP() + 1 < height && rooms[p.getRowP() + 1][p.getColP()].getEvent() != NULL)){
	
	rooms[p.getRowP() + 1][p.getColP()].getEvent()->percept();
}	
//check if room above player has a event
if(p.getRowP() - 1 >= 0 && rooms[p.getRowP() - 1][p.getColP()].getEvent() != NULL){
	//print percept
	rooms[p.getRowP() - 1][p.getColP()].getEvent()->percept();
}
//check if room to the right of player has an event
if(p.getColP() + 1 < width && rooms[p.getRowP()][p.getColP() + 1].getEvent() != NULL){
	//print percept 
	rooms[p.getRowP()][p.getColP() + 1].getEvent()->percept();

}
//check if room to the left of player has an event
if(p.getColP() - 1 >= 0 && rooms[p.getRowP()][p.getColP() - 1].getEvent() != NULL){
	//print percept
	rooms[p.getRowP()][p.getColP() - 1].getEvent()->percept();

}
else{

}
	
}

void game::moveWumpus(){
	bool noWumpus = true;
srand(static_cast<unsigned>(time(0)));
	std::cout << "start of move wumpus" << std::endl;
	do{
		//find a rand digit between 0-3 for moving the wumpus if arrow misses the wumpus
		int move = rand() % 4;
	if(getWumpusAlive()){
		std::cout << move << std::endl;
		//check to make sure direction is valid,(so it doesnt go out of bounds or go into another room with an event)
		if(move == 0 && getWRow() + 1 <= height && rooms[getWRow()+ 1][getWCol()].getEvent() == NULL){
			//set old wumpus to null
			rooms[getWRow()][getWCol()].setRoomEvent(nullptr);
			//make newwumpus in the new spot
			rooms[getWRow() + 1][getWCol()].setRoomEvent(new wumpus);
			//update row for wumpus 
			setWRow(getWRow()+1);
			noWumpus = false;
		}
			//check to make sure direction is valid,(so it doesnt go out of bounds or go into another room with an event)
		else if(move == 1 && getWRow() - 1 >= 0 && rooms[getWRow()-1][getWCol()].getEvent() == NULL){
		//set old wumpus to null
			rooms[getWRow()][getWCol()].setRoomEvent(nullptr);
			//make new wumpus 
			rooms[getWRow() - 1][getWCol()].setRoomEvent(new wumpus);
			//update row for wumpus
			setWRow(getWRow()-1);
			noWumpus = false;
		}
			//check to make sure direction is valid,(so it doesnt go out of bounds or go into another room with an event)
		else if(move == 2 && getWCol() + 1 <= width && rooms[getWRow()][getWCol()+ 1].getEvent() == NULL){
			//set old wumpus to null
			rooms[getWRow()][getWCol()].setRoomEvent(nullptr);
			//make new wumpus 
			rooms[getWRow()][getWCol()+ 1].setRoomEvent(new wumpus);
			//update wumpus col
			setWCol(getWCol()+ 1);
			noWumpus = false;
		}
			//check to make sure direction is valid,(so it doesnt go out of bounds or go into another room with an event)
		else if(move == 3 && getWCol() - 1 >= 0 && rooms[getWRow()][getWCol() -1].getEvent() == NULL){
			//set old wumpus to null
			rooms[getWRow()][getWCol()].setRoomEvent(nullptr);
			//make new wumpus 
			rooms[getWRow()][getWCol() -1].setRoomEvent(new wumpus);
			//update wumpus col
			setWCol(getWCol()- 1);
			noWumpus = false;

		}
		
		//else is to make sure code runs untill valid direction is found 
		else{
			std::cout << "this is else " << std::endl;
			noWumpus = true;
		}
		//setRoomEvent();
	}
}while(noWumpus);
}
