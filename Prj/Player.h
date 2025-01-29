#ifndef PRJ_PLAYER_H
#define PRJ_PLAYER_H
#include <string>
#include "Card.h"
using namespace std;

class Player{
private:
    string name;
    int score;
    bool skipNextTurn;
public:
    Player(string name);
    string getName();
    void setName(string name);
    int getScore();
    void setScore(int score);
    void adjustScore(int points) { score += points; }
    void updatescore(Card*card1,Card*card2);
    void displayScore();
   bool  getSkipNextTurn();
    void setSkipNextTurn(bool skipNextTurn);
    ~Player();
};
#endif
