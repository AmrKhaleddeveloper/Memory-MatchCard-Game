#ifndef PRJ_GAME_H
#define PRJ_GAME_H
#include "Deck.h"
#include "Player.h"

class Game{
private:
    Deck* deck;
    Player* p1;
    Player* p2;
    Player* currentPlayer;


public:
    Game();
    Game(Player* p1,Player* p2);
    Deck* getDeck();
    void setDeck(Deck* d);
    Player* getPlayer1();
    void setPlayer1(Player* p1);
    Player* getPlayer2();
    void setPlayer2(Player* p2);
    void switchPlayer();
    void playTurn();
    void intializeGame();
    void startGame();
    void announceWinner();
    ~Game();
};
#endif //PRJ_GAME_H
