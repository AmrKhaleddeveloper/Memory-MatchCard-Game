#ifndef PRJ_BONUSCARD_H
#define PRJ_BONUSCARD_H

#include "Card.h"

class BonusCard : public Card{
private:
    int points;
public:
    BonusCard();
    BonusCard(int number);
    int getBonusPoints();
    ~BonusCard();
};
#endif
