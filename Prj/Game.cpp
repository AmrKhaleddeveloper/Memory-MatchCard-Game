#include "Game.h"
#include <iostream>
#include "BonusCard.h"
#include "StandardCard.h"
#include "PenaltyCard.h"
using namespace std;
// Default constructor
Game::Game() {
    deck = new Deck();
    p1 = new Player("");
    p2 = new Player("");
}
// Constructor with player parameters
Game::Game(Player* p1 , Player* p2) {
    deck = new Deck();
    this->p1 = p1;
    this->p2 = p2;
}
// Getter for player 1
Player* Game::getPlayer1() {
    return this->p1;
}
// Getter for player 2
Player* Game::getPlayer2() {
    return this->p2;
}

// Getter for deck
Deck* Game::getDeck() {
    return this->deck;
}

// Setter for player 1
void Game::setPlayer1(Player *p1) {
    this->p1 = p1;
}

// Setter for player 2
void Game::setPlayer2(Player *p2) {
    this->p2 = p2;
}

// Setter for deck
void Game::setDeck(Deck* deck) {
    this->deck = deck;
}

// Switches the current player
void Game::switchPlayer() {
    //handling if the player chosed to skip next turn
    currentPlayer = (currentPlayer == p1) ? p2 : p1;
    if (currentPlayer->getSkipNextTurn() == true) {
        currentPlayer->setSkipNextTurn(false);
        currentPlayer = (currentPlayer == p1) ? p2 : p1;
    }
}
// Starts the game by setting player names and shuffling the deck
void Game::startGame() {
    string name;
    cout << "Enter Player 1 Name: ";
    cin >> name;
    p1->setName(name);
    cout << "Enter Player 2 Name: ";
    cin >> name;
    p2->setName(name);
    currentPlayer = p1;
    deck->shuffle();
    cout<<"Player Name: "<<currentPlayer->getName()<<endl;
    currentPlayer->displayScore();
    if (currentPlayer->getName()==p1->getName()) {
        cout << "Player Name: " << p2->getName() << endl;
        p2->displayScore();
    }else{
        cout << "Player Name: " << p1->getName() << endl;
        p1->displayScore();
    }
}

// Handles a single turn of the game
void Game::playTurn() {
    int x1, y1, x2, y2;
    Card *c1 = nullptr;
    Card *c2 = nullptr;

    // Get the first card
    do {
        cout << currentPlayer->getName() << "'s Turn. Enter first card (row, col): ";
        cin >> x1 >> y1;
        bool validFirstCoordinate = (x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4);
        if (validFirstCoordinate) {
            c1 = deck->getCard(x1, y1);
        }
        if (!validFirstCoordinate || !c1) {
            cout << "Invalid first card selection. Try again." << endl;
        }
    } while (!c1);

    // Get the second card
    do {
        cout << "Enter second card (row, col): ";
        cin >> x2 >> y2;
        bool validSecondCoordinate = (x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4);
        if (validSecondCoordinate) {
            c2 = deck->getCard(x2, y2);
        }
        if (!validSecondCoordinate || !c2) {
            cout << "Invalid second card selection. Try again." << endl;
        }
    } while (!c2);

    // Ensure the two cards are not the same
    do {
        if (x1 == x2 && y1 == y2) {
            cout << "Both coordinates are the same. Try again." << endl;
            cout << "Enter second card (row, col): ";
            cin >> x2 >> y2;
            bool validSecondCoordinate = (x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4);
            if (validSecondCoordinate) {
                c2 = deck->getCard(x2, y2);
            }
        }
    } while (x1 == x2 && y1 == y2);
    // Reveal the selected cards
    c1->setIsFaceUp(true);
    c2->setIsFaceUp(true);
    deck->displayGrid();
    c1->setIsFaceUp(false);
    c2->setIsFaceUp(false);
    // Check if the cards match
    if (c1->getNumber() == c2->getNumber()) {
        cout << "Matched!" << endl;
        if (c1->getNumber() == 7 && c2->getNumber() == 7) {
            int choice;
            do {
                cout << "You have two options to choose from:\n1. Gain 2 points\n2. Gain 1 point and take another next turn\n";
                cin >> choice;
                if (choice != 1 && choice != 2) {
                    cout << "Invalid choice. You must select either 1 or 2." << endl;
                }
            } while (choice != 1 && choice != 2);
            if (choice == 1) {
                currentPlayer->adjustScore(2);
                deck->removeCard(x1, y1);
                deck->removeCard(x2, y2);
                switchPlayer();
            } else if (choice == 2) {
                deck->removeCard(x1, y1);
                deck->removeCard(x2, y2);
                currentPlayer->adjustScore(1);
            }
        } else if (c1->getNumber() == 8 && c2->getNumber() == 8) {
            int choice;
            do {
                cout << "You have two options to choose from:\n1. Lose 2 points\n2. Lose 1 point and skip the next turn\n";
                cin >> choice;
                if (choice != 1 && choice != 2) {
                    cout << "Invalid choice. You must select either 1 or 2." << endl;
                }
            } while (choice != 1 && choice != 2);
            if (choice == 1) {
                currentPlayer->adjustScore(-2);
                deck->removeCard(x1, y1);
                deck->removeCard(x2, y2);
                switchPlayer();
            } else if (choice == 2) {
                currentPlayer->adjustScore(-1);
                deck->removeCard(x1, y1);
                deck->removeCard(x2, y2);
                currentPlayer->setSkipNextTurn(true);
                switchPlayer();
            }
        } else {
            currentPlayer->adjustScore(1);
            deck->removeCard(x1, y1);
            deck->removeCard(x2, y2);
        }
    } else {
        // Handle non-matching cards
        if (c1->getNumber() == 7 && c2->getNumber() == 8 || c1->getNumber() == 8 && c2->getNumber() == 7) {
            cout << "Penalty and BonusCard cards are revealed!" << endl;
            deck->removeCard(x1, y1);
            deck->removeCard(x2, y2);
            switchPlayer();
        } else if (c1->getNumber() == 7 && c2->getNumber() != 8 || c1->getNumber() != 8 && c2->getNumber() == 7) {
            cout << "Bonus card revealed!" << endl;
            currentPlayer->adjustScore(1);
            if (c1->getNumber() == 7) {
                deck->removeCard(x1, y1);
                c2->setIsFaceUp(false);
            } else {
                deck->removeCard(x2, y2);
                c1->setIsFaceUp(false);
            }
            switchPlayer();
        } else if (c1->getNumber() == 8 && c2->getNumber() != 7 || c1->getNumber() != 7 && c2->getNumber() == 8) {
            cout << "Penalty card revealed!" << endl;
            currentPlayer->adjustScore(-1);
            if (c1->getNumber() == 8) {
                deck->removeCard(x1, y1);
                c2->setIsFaceUp(false);
            } else {
                deck->removeCard(x2, y2);
                c1->setIsFaceUp(false);
            }
            switchPlayer();
        } else {
            cout << "Not Matched!" << endl;
            switchPlayer();
        }
    }
    if (!deck->isEmpty()){
        cout<<"======================================================"<<endl;
        cout<<"Next Turn"<<endl;
        cout<<"Player Name: "<<currentPlayer->getName()<<endl;
        currentPlayer->displayScore();
        if (currentPlayer->getName()==p1->getName()) {
            cout << "Player Name: " << p2->getName() << endl;
            p2->displayScore();
        }else{
            cout << "Player Name: " << p1->getName() << endl;
            p1->displayScore();
        }
    }
}

// Announces the winner of the game
void Game::announceWinner() {
    cout << "The Game has ended" << endl;
    if (p1->getScore() > p2->getScore()) {
        cout << p1->getName() << " wins!" << endl;
        cout <<p1->getName()<<"'s Score: "<<p1->getScore() << endl;
    } else if (p2->getScore() > p1->getScore()) {
        cout << p2->getName() << " wins!" << endl;
        cout<<p2->getName()<<"'s Score: " <<p2->getScore() << endl;
    } else {
        cout << "It's a tie!" << endl;
        cout<<p1->getName()<<endl;
        cout <<p1->getName()<<"'s Score: "<<p1->getScore() << endl;
        cout<<p2->getName()<<endl;
        cout<<p2->getName()<<"'s Score: " <<p2->getScore() << endl;
    }
}
// Initializes the game and starts the game loop
void Game::intializeGame() {
    startGame();
    while (!deck->isEmpty()) {
        deck->displayGrid();
        playTurn();
    }
    announceWinner();
}
// Destructor to clean up dynamically allocated memory
Game::~Game() {
    delete deck;
    delete p1;
    delete p2;
    delete currentPlayer;
};