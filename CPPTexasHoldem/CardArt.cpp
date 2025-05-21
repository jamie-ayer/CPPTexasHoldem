//
//  CardArt.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include "CardArt.hpp"
#include "Card.hpp"
#include <iostream>

using namespace std;

vector<string> CardArt::RenderCard(const Card& card) {
    string rank;
    string suit;

    vector<string> fullCardAscii;
    fullCardAscii.push_back("┌──────┐");
    if(card.GetCardValAscii() != "10")
        fullCardAscii.push_back("|" + card.GetCardValAscii() + "     |");
    else
        fullCardAscii.push_back("|" + card.GetCardValAscii() + "    |");
    fullCardAscii.push_back("|      |");
    fullCardAscii.push_back("|  " + card.GetSuitAscii() + "   |");
    fullCardAscii.push_back("|      |");
    if(card.GetCardValAscii() != "10")
        fullCardAscii.push_back("|     " + card.GetCardValAscii() + "|");
    else
        fullCardAscii.push_back("|    " + card.GetCardValAscii() + "|");
    fullCardAscii.push_back("└──────┘");

    return fullCardAscii;
}

void CardArt::RenderMultCards(const vector<Card>& cards) {
    
    vector<vector<string>> rendedCards;
    
    for(const Card& c : cards) {
        rendedCards.push_back(CardArt::RenderCard(c));
        }

    for(size_t line = 0; line < rendedCards[0].size(); ++line) {
        for (const auto& card : rendedCards) {
            cout << card[line] << " ";
        }
        cout << "\n";
        
    }
}

string CardArt::FormatCardAscii(Card::CardValue value, Card::Suit suit) {
    Card temp(suit, value);
    return temp.ToString();
}
