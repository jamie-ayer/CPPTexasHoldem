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
    if (cardVal == CardValue::TWO) cardName = "Two";
    else if (cardVal == CardValue::THREE) cardName = "Three";
    else if (cardVal == CardValue::FOUR) cardName = "Four";
    else if (cardVal == CardValue::FIVE) cardName = "Five";
    else if (cardVal == CardValue::SIX) cardName = "Six";
    else if (cardVal == CardValue::SEVEN) cardName = "Seven";
    else if (cardVal == CardValue::EIGHT) cardName = "Eight";
    else if (cardVal == CardValue::NINE) cardName = "Nine";
    else if (cardVal == CardValue::TEN) cardName = "Ten";
    else if (cardVal == CardValue::JACK) cardName = "Jack";
    else if (cardVal == CardValue::QUEEN) cardName = "Queen";
    else if (cardVal == CardValue::KING) cardName = "King";
    else if (cardVal == CardValue::ACE) cardName = "Ace";
    
    // Switch statement for return string value of Suit enum
    switch(suit){
        case Suit::DIAMONDS:
            cardSuit = "Diamonds";
            break;
        case Suit::CLUBS:
            cardSuit = "Clubs";
            break;
        case Suit::SPADES:
            cardSuit = "Spades";
            break;
        case Suit::HEARTS:
            cardSuit = "Hearts";
            break;
    }
    
    return cardName + " of " + cardSuit;
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
