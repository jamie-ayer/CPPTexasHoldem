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

void Table::AddCardToRiver(int amount){
    for(int i = 0; i < amount; i++)
        riverCards.push_back(gameDeck.DealSingleCard());
}

void Table::AddCardsToRiver(vector<Card>& cards){
    riverCards = cards;
}

vector<Card> Table::GetRiverCards(){
    return riverCards;
}

size_t Table::RiverAmount(){
    return riverCards.size();
}

void Table::RemoveCardsFromRiver(){
    discardPile.insert(discardPile.end(), riverCards.begin(), riverCards.end());
    riverCards.clear();
}

void Table::AddCardsToDiscardPile(const vector<Card> &cards){
    discardPile.insert(discardPile.end(), cards.begin(), cards.end());
}

void Table::RenderRiver(){
    
    cout << "------------------------------------------" << endl;
    if(riverCards.empty()){
        cout << "\n\n\n\n\n\n\n" << endl;
    }
    else{
        CardArt::RenderMultCards(riverCards);
    }
    
    cout << "------------------------------------------" << endl;
}

Card Table::DealCard(){
    return gameDeck.DealSingleCard();
}


