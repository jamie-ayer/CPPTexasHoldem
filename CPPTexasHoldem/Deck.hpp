//
//  Deck.hpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#ifndef DECK_HPP
#define DECK_HPP

#include <stdio.h>
#include <vector>
#include "Card.hpp"

using namespace std;

class Deck{
public:
    Deck();
    
    void Shuffle();
    Card DealSingleCard();
    
    bool CheckDeckEmpty();
    
    void PrintDeck();
    
private:
    vector<Card> cards;
};

#endif
