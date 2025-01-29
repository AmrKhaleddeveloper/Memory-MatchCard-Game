#ifndef PRJ_STANDARDCARD_H
#define PRJ_STANDARDCARD_H


#include "Card.h"

class StandardCard: public Card{
public:
    StandardCard();
    StandardCard(int number);
    ~StandardCard();
};

#endif
