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
    Card backCard = cards.back();
    cards.pop_back();
    return backCard;
}

void Deck::Shuffle(){
    cout << "\n\nSHUFFLING CARDS\n\n" << endl;
    
    random_device rd;
    mt19937 g(rd());
    
    shuffle(cards.begin(), cards.end(), g);
    
    // First thought was the code below, I learned C11 had newer better functions above
    /*
    srand(static_cast<unsigned int>(time(nullptr)));
    
    for(int i = 0; i < cards.size(); i++){
        int j = i + (rand() % (cards.size() - i));
        Card tmpCard = cards[i];
        cards[i] = cards[j];
        cards[j] = tmpCard;
        swap(cards[i], cards[j]); // Built in swap I didn't know c++ had
    } */
}

bool Deck::CheckDeckEmpty(){
    return cards.empty();
}
