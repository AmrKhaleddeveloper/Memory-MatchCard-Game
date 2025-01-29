#include "Player.h"
#include <iostream>
#include "Card.h"
using namespace std;

//Player

Player::Player(string name) {
    this->name=name;
    this->score=0;
    skipNextTurn= false;
}
string Player::getName() {
    return name;
}

int Player::getScore() {
    return score;
}

void Player::setName(string name){
    this->name = name;
}

void Player::setScore(int score){
    this->score = score;
}

void Player::displayScore(){
    cout << this->name<<" Current Score: " <<score<<endl;
}
void Player::setSkipNextTurn(bool skipNextTurn) { this->skipNextTurn = skipNextTurn ;}
bool Player::getSkipNextTurn() { return skipNextTurn; }

Player::~Player() {};