#include "Deck.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "iostream"
#include <ctime>
using namespace std;
// Constructor for Deck class
Deck::Deck() {
    grid = new Card*[16];// Allocate memory for 16 cards
    remainingCards=16;// Initialize remaining cards count
    for (int i = 0; i < 16; i++) {
        grid[i] = nullptr; // Initialize all pointers to nullptr
    }
    int randomNumber = 1;
    for (int i = 0; i < 12; i+=2) {
        grid[i] = new StandardCard(randomNumber);// Create pairs of StandardCards
        grid[i+1] = new StandardCard(randomNumber);
        randomNumber++;
    }
    int bonus = 7,penalty = 8;
    grid[12] = new BonusCard(bonus);
    grid[13] = new BonusCard(bonus);
    grid[14] = new PenaltyCard(penalty);// Create BonusCards
    grid[15] = new PenaltyCard(penalty);
}


void Deck::shuffle() {
    srand(time(0));// Seed random number generator
    for (int i = 16 - 1; i > 0; i--) {
        int j = rand() % (i + 1);// Generate a random index
        swap(grid[i], grid[j]);// Swap cards
    }
}
void Deck::displayGrid() {
    for (int i = 0; i < 16; i++) {
        if (grid[i] != nullptr) {
            grid[i]->display();
        } else {
            cout << "  "; // Print empty space for null cards
        }
        if ((i + 1) % 4 == 0)
            cout << endl;
    }
    cout << endl;
}
Card*Deck::getCard(int x, int y) {
    return grid[x * 4 + y];
}
// Check if the deck is empty
bool Deck::isEmpty() {
    return remainingCards <= 1; // Check if remaining cards are less than or equal to 1
}

void Deck::removeCard(int x, int y) {
    int index = x * 4 + y;
    if (grid[index] != nullptr) {
        delete grid[index];
        grid[index] = nullptr;
        remainingCards--;
    }
}

Deck::~Deck() {
    for (int i = 0; i < 16; i++)
        delete grid[i];
    delete[]grid;
}