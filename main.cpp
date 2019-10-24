/* Siyu (Eva) Wu
 * Project 5
 * */
#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    //declare all the variables

    bool play, invalid, guessedHigher;
    string response;
    Card compValue, userValue;
    int nwin;
    int nlose;
    int ntie;
    int ncount;
    srand(time(NULL));

    //game begin
    cout << "Welcome to Blind Man's Bluff" << endl ;
    play = true;//check player if they wants to play again
    //create deck, discarded deck, then populate and shuffle the card
    Deck deck;
    Deck discard;
    deck.populateDeck();
    deck.shuffleCard();
    //start if player replay, and count smaller than 26
    while(play && ncount < 26) {
        //deals card
        compValue = deck.removeCard();
        userValue = deck.removeCard();
        //adds cards to discard
        discard.addCard(compValue);
        discard.addCard(userValue);

        // get user's bet
        cout << "Computer's value is " << compValue.cardValue() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if((compValue.cardValue() < userValue.cardValue() && guessedHigher) || (compValue.cardValue() > userValue.cardValue() && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nwin++;
        } else if((compValue.cardValue() > userValue.cardValue() && guessedHigher) || (compValue.cardValue() < userValue.cardValue() && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nlose++;
        } else {
            cout << "It's a tie:" << endl;
            ntie++;
        }
        cout << "\tyour value is " << userValue.cardValue() << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
        ncount++;
    }
    //if count = 26, finish the game
    if(ncount == 26){
        cout<<"No cards to play , please restart."<<endl;
    }
    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nwin << "-" << nlose << "-" << ntie << " (W-L-T)" << endl;

    return 0;
}