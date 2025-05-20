//
//  Table.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include "Table.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "CardArt.hpp"
#include <iostream>
#include <vector>

using namespace std;

Table::Table(){
    gameDeck = Deck();
    gameDeck.Shuffle();
}

void Table::AddCardToRiver(){
    riverCards.push_back(gameDeck.DealSingleCard());
}

void Table::RemoveCardsFromRiver(){
    discardPile.insert(discardPile.end(), riverCards.begin(), riverCards.end());
    riverCards.clear();
}

void Table::RenderRiver(){
    
    cout << "-------------------------------------" << endl;
    if(riverCards.empty()){
        cout << "\n\n\n\n\n\n\n" << endl;
    }
    else{
        CardArt::RenderMultCards(riverCards);
    }
    
    cout << "-------------------------------------" << endl;
}


