//
//  main.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"

using namespace std;



int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "\nASCII Texas Holdem\n";
    
    
    cout << "Creating Deck()\n" << endl;
    Deck deck = Deck();
    
    cout << "Deck created, printing deck\n" << endl;
    
    deck.PrintDeck();
    deck.Shuffle();
    deck.PrintDeck();
    
    /*
    string inpSuit;
    string inpVal;
    cout << "\nTest card Suit" << endl;
    cin >> inpSuit;
    cout << "\nTest card Val" << endl;
    cin >> inpVal;
    
    Card c = Card(Card::ParseSuit(inpSuit), Card::ParseValue(inpVal));
    
    cout << "\n\nCard constructed success: " << c.ToString() << endl;
     */
    
    
    
    
    return 0;
}
