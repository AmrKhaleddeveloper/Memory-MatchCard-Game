#ifndef PRJ_DECK_H
#define PRJ_DECK_H

#include "Card.h"

class Deck{
private:
    Card** grid;
    int remainingCards;
public:
    Deck();
    Card* getGrid();
    void setGrid(Card* grid);
    void shuffle();
    Card* getCard(int x, int y);
    bool isEmpty();
    void removeCard(int x, int y);
    void displayGrid();
    ~Deck();


};
#endif
