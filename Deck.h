/* Siyu (Eva) Wu
 * Project 5
 * */
#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck(); //default constructor
    Deck (const Deck& C );//copy constructor
    Deck& operator= (const Deck& rhs );//copy assignment operator
    ~Deck();//destructor
    void populateDeck();//populates the deck
    void shuffleCard(); //shuffles the cards
    Card removeCard();//remove a card
    bool addCard(Card v);//adds a card to the discard cards
    void discardPrint();//prints out the discard cards


private:
    Card* cards;
    int arraySize;
    int cardsLeft;
    int current;
};


#endif //BLINDMANSBLUFF_DECK_H
