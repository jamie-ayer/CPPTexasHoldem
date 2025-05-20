//
//  Card.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include "Card.hpp"
#include <unordered_map>
#include <string>
#include <array>

using namespace std;

// Constructor
Card::Card(Suit suit, CardValue cardVal) {
    this->suit = suit;
    this->cardVal = cardVal;
}

// Getter for Suit
Card::Suit Card::GetSuit() const {
    return suit;
}

// Getter for CardValue
Card::CardValue Card::GetCardVal() const {
    return cardVal;
}

// ToString function (takes suit and value enums and converts to string)
string Card::ToString() const {
    string cardName;
    string cardSuit;
    
    // If else statements return string value of CardValue enum
    if (cardVal == CardValue::TWO) cardName = "2";
    else if (cardVal == CardValue::THREE) cardName = "3";
    else if (cardVal == CardValue::FOUR) cardName = "4";
    else if (cardVal == CardValue::FIVE) cardName = "5";
    else if (cardVal == CardValue::SIX) cardName = "6";
    else if (cardVal == CardValue::SEVEN) cardName = "7";
    else if (cardVal == CardValue::EIGHT) cardName = "8";
    else if (cardVal == CardValue::NINE) cardName = "9";
    else if (cardVal == CardValue::TEN) cardName = "10";
    else if (cardVal == CardValue::JACK) cardName = "J";
    else if (cardVal == CardValue::QUEEN) cardName = "Q";
    else if (cardVal == CardValue::KING) cardName = "K";
    else if (cardVal == CardValue::ACE) cardName = "A";
    
    // Switch statement for return string value of Suit enum
    switch(suit){
        case Suit::DIAMONDS:
            cardSuit = "\u2666";
            break;
        case Suit::CLUBS:
            cardSuit = "\u2663";
            break;
        case Suit::SPADES:
            cardSuit = "\u2660";
            break;
        case Suit::HEARTS:
            cardSuit = "\u2665";
            break;
    }
    
    return "|" + cardName + cardSuit + "|";
}

// Map of string to suit
const unordered_map<string, Card::Suit> Card::suitMap = {
    {"hearts", Card::Suit::HEARTS},
    {"spades", Card::Suit::SPADES},
    {"clubs", Card::Suit::CLUBS},
    {"diamonds", Card::Suit::DIAMONDS}
};

// Map of string to card value
const unordered_map<string, Card::CardValue> Card::valueMap = {
    {"2", Card::CardValue::TWO},
    {"3", Card::CardValue::THREE},
    {"4", Card::CardValue::FOUR},
    {"5", Card::CardValue::FIVE},
    {"6", Card::CardValue::SIX},
    {"7", Card::CardValue::SEVEN},
    {"8", Card::CardValue::EIGHT},
    {"9", Card::CardValue::NINE},
    {"10", Card::CardValue::TEN},
    {"jack", Card::CardValue::JACK},
    {"queen", Card::CardValue::QUEEN},
    {"king", Card::CardValue::KING},
    {"ace", Card::CardValue::ACE}
};

// Parse user input to suit enum
Card::Suit Card::ParseSuit(const string& input){
    return suitMap.at(input);
}

// Parse user input to value enum
Card::CardValue Card::ParseValue(const string& input){
    return valueMap.at(input);
}
