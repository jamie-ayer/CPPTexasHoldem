//
//  Hand.hpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#ifndef HAND_HPP
#define HAND_HPP

#include <stdio.h>
#include <vector>
#include "Card.hpp"

using namespace std;

class Hand{
public:
    Hand();
    void PrintHand();
    size_t CardAmount();
    void AddCards(const Card& card);
    void RemoveCards();
    bool HandHasCards();
    bool IsActive();
    void Fold();
    void UnFold();
    vector<Card> GetHand();
    
private:
    vector<Card> cardsInHand;
    bool folded;
    
    
};

#endif
