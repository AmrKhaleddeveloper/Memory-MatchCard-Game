#include "BonusCard.h"
using namespace std;
BonusCard::BonusCard(int number) :Card(7),points(2){};
BonusCard::BonusCard() : Card(7) { points = 2; }
int BonusCard::getBonusPoints() { return points; }
BonusCard::~BonusCard() {};