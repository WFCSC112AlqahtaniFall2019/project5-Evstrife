/* Siyu (Eva) Wu
 * Project 5
 * */
#include "Card.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor definition, assign rank and suit to 0
Card::Card(){
    int rank = 0;
    int suit = 0;
}
//alternative constructor definition
Card::Card(int rank,int suit){
     rankN = rank;
     suitT  = suit;
}
//overloaded comparison constructor
bool  Card::operator <(Card c){
    if(this->rankN > c.rankN){
        return true;
    } else if (this->rankN < c.rankN){
        return false;
    } else if (this->rankN == c.rankN){
        if(this->suitT > c.suitT){
            return true;
        } else{
            return false;
        }
    }
}
//return a string showing the value of card, as "rank of suit"
string Card::cardValue(){
    value = ranks[rankN]+ " of "+ suits[suitT];
    return value;
}