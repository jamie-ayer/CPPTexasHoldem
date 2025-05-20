//
//  CardArt.hpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#ifndef CARD_ART_HPP
#define CARD_ART_HPP

#include "Card.hpp"
#include <vector>
#include <string>

using namespace std;

namespace CardArt {
    vector<string> RenderCard(const Card& card);
    void RenderMultCards(const vector<Card>& cards);
}

#endif
