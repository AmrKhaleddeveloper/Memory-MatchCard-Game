#ifndef PRJ_CARD_H
#define PRJ_CARD_H

class Card{
protected:
    int number;
    bool isFaceUp;

public:
    Card();
    Card(int number);
    virtual int getNumber();
    virtual void setNumber(int number);
    virtual bool getIsFaceUp();
    virtual void setIsFaceUp(bool isFaceUp);
    virtual void reveal();
    virtual void hide();
    virtual void display();
    virtual ~Card();
};

#endif
