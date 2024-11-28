#include <iostream>
#include "player.hpp"
//this is my new player class



//constructor
player::player(bool isAlive, bool isConfused, bool hasGold, int numArrows): isAlive(isAlive), isConfused(isConfused), hasGold(hasGold),numArrows(numArrows){

}


//player();
    //player(bool isAlive, bool isConfused, bool hasGold, int numArrows);
    void player::setIsAlive(bool isAlive){
        this->isAlive = isAlive;}
    void player::setIsConfused(bool isConfused){
        this->isConfused = isConfused;}
    void player::setHasGold(bool hasGold){
        this->hasGold = hasGold;}
    void player::setNumArrows(int numArrows){
        this->numArrows = numArrows;}
    void player::setRowP(int rowP){
        this->rowP = rowP;}
    void player::setColP(int colP){
        this->colP = colP;}

    bool player::getIsAlive(){
        return this->isAlive;}
    bool player::getIsConfused(){
        return this->isConfused;}
    bool player::getHasGold(){
        return this->hasGold;}
    int player::getNumArrows(){
        return this->numArrows;}
    int player::getRowP(){
        return this->rowP;}
    int player::getColP(){
        return this->colP;}
    