#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {
    public:
        //default constructor
        Card();
        //alternate constructor
        Card(int rank, int suit);
        //overloaded comparison operator
        bool operator <(Card c);
        //return the rank and suit of card
        string cardValue();
    private:
        //declare private card members
        int rankN;
        int suitT;
        string value;

};


#endif //BLINDMANSBLUFF_CARD_H
