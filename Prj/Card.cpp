
//Card

#include "Card.h"
#include "iostream"
using namespace std;
Card::Card(){};

Card::Card(int number) {
    this->number=number;
    this->isFaceUp= false;
}

int Card::getNumber() {
    return this->number ;
}

void Card::setNumber(int num) {
    this->number=num;
}

bool Card::getIsFaceUp() {
    return isFaceUp;
}

void Card::setIsFaceUp(bool isFaceUp) {
    this->isFaceUp=isFaceUp;
}
void Card::reveal() {
    this->isFaceUp= true;
}
void Card::hide() {
    this->isFaceUp=false;
}
void Card::display() {
    if (isFaceUp){
        cout<<number<<" ";
    }else{
        cout<<"*"<<" ";
    }
}

Card::~Card() {};