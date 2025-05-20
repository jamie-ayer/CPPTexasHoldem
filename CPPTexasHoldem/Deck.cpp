//
//  Deck.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include "Deck.hpp"
#include <iostream>
#include <random>

using namespace std;

Deck::Deck(){
    cout << "In deck constructor";
    for(int i = 0; i < 4; i++){
        for(int j = 2; j < 15; j++){
            Card::Suit suit = static_cast<Card::Suit>(i);
            Card::CardValue val = static_cast<Card::CardValue>(j);
            cards.push_back(Card(suit, val));
        }
    }
}

void Deck::PrintDeck(){
    cout << "\n\nPRINTING DECK\n\n" << endl;
    
    for(int i = 0; i < cards.size(); i++){
        cout << cards[i].ToString() << " ";
        if((i + 1) % 13 == 0)
            cout << endl;
    }
}

Card Deck::DealSingleCard(){
    cout << "\nDealing single card" << endl;
    Card backCard = cards.back();
    cout << "Card dealt: " << backCard.ToString() << endl;
    cards.pop_back();
    return backCard;
}

void Deck::Shuffle(){
    cout << "\n\nSHUFFLING CARDS\n\n" << endl;
    
    random_device rd;
    mt19937 g(rd());
    
    shuffle(cards.begin(), cards.end(), g);
}

bool Deck::CheckDeckEmpty(){
    return cards.empty();
}
