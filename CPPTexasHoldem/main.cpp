//
//  main.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include <iostream>
#include "Card.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "\nASCII Texas Holdem\n";
    
    
    string inpSuit;
    string inpVal;
    cout << "\nTest card Suit" << endl;
    cin >> inpSuit;
    cout << "\nTest card Val" << endl;
    cin >> inpVal;
    
    Card c = Card(Card::ParseSuit(inpSuit), Card::ParseValue(inpVal));
    
    cout << "\n\nCard constructed success: " << c.ToString() << endl;
    
    
    
    
    return 0;
}
