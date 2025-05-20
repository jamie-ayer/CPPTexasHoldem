//
//  Card.hpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <unordered_map>

using namespace std;

class Card {
public:
    enum class Suit { DIAMONDS, CLUBS, SPADES, HEARTS };
    enum class CardValue {
        TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
        NINE, TEN, JACK, QUEEN, KING, ACE};

    Card(Suit suit, CardValue cardVal);

    Suit GetSuit() const;
    CardValue GetCardVal() const;
    string ToString() const;
    
    static Suit ParseSuit(const string& input);
    static CardValue ParseValue(const string& input);

private:
    Suit suit;
    CardValue cardVal;
    static const unordered_map<string, Suit> suitMap;
    static const unordered_map<string, CardValue> valueMap;
};

#endif 

