/* Siyu (Eva) Wu
 * Project 5
 * */
#include "Deck.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor definition, to assign every card
Deck::Deck(){
    arraySize = 52;
    cards = new Card[arraySize];
    current = 0;
    cardsLeft = 52;
}
//copy constructor definition, make a copy of data members
Deck::Deck (const Deck& C ){
    arraySize = C.arraySize;
    cards = new Card[arraySize];
    for (int i=0; i<arraySize;i++){
        cards[i]=C.cards[i];
    }
    current=C.current;
    cardsLeft=C.cardsLeft;
}

//copy assignment operator, using temp to allow = operator
Deck& Deck::operator= (const Deck& C ){
    Deck temp(C);
    swap(cards, temp.cards);
    return *this;
}

//destructor, delete arrays
Deck::~Deck() {
        delete [] cards;
}

// shuffle cards for cardsLeft*cardsLeft times
void Deck::shuffleCard() {
    srand(time(0));
    int num = cardsLeft * cardsLeft;
    for (int j = 0; j < num; j++) {
        int c1 = rand() % 52;
        int c2 = rand() % 52;
        swap(c1,c2);
    }
}
//populate the deck with 52 cards, 4 types of 13 ranks
void Deck::populateDeck() {
    int cur = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            Card c = Card(j, i);
            cards[cur] = Card(j, i);
            cur++;
        }
    }
}
//remove a card from the deck, if there's card left

Card Deck::removeCard() {
    if (current < arraySize) {
        cardsLeft--;
        return (cards[current++]);
    } else{
        cout<<"No cards left."<<endl;
    }
}
//add card to the deck, if there's a s, return true, if there's no space, return false
bool Deck::addCard(Card v) {
    if (cardsLeft > 0){
        cards[current] = v;
        current++;
        return true;
    } else{
        return false;
    }
}

//prints out the discard pile
void Deck::discardPrint(){
    cout<<"Discarded Cards: ";
    for (int i = 0; i < current; ++i) {
        cout<<cards[i].cardValue()<<"   ";
    }
    cout<<endl;
}



