//
//  Table.hpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#ifndef TABLE_HPP
#define TABLE_HPP

#include <stdio.h>
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>

using namespace std;

class Table{
public:
    Table();
    void AddCardToRiver();
    void RemoveCardsFromRiver();
    void RenderRiver();
    Deck gameDeck;
private:
    vector<Card> riverCards;
    vector<Card> discardPile;
};

#endif
