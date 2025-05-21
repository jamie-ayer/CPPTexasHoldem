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
    void AddCardToRiver(int amount);
    void RemoveCardsFromRiver();
    void AddCardsToDiscardPile(const vector<Card>& cards);
    void RenderRiver();
    void AddCardsToRiver(vector<Card>& cards);
    vector<Card> GetRiverCards();
    Card DealCard();
    size_t RiverAmount();
    
private:
    Deck gameDeck;
    vector<Card> riverCards;
    vector<Card> discardPile;
};

#endif
