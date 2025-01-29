#ifndef PENALTY_CARD_H
#define PENALTY_CARD_H

#include "Card.h"

class PenaltyCard : public Card {
private:
    int points;

public:
    PenaltyCard();
    PenaltyCard(int number);
    int getPenaltyPoints();
    ~PenaltyCard();
};

#endif // PENALTY_CARD_H
