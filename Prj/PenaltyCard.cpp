#include "PenaltyCard.h"

PenaltyCard::PenaltyCard() : Card(8) { points = -1; }
PenaltyCard::PenaltyCard(int number) : Card(number) { points = -1; }
int PenaltyCard::getPenaltyPoints() { return points; }
PenaltyCard::~PenaltyCard() {}
