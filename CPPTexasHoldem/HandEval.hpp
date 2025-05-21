//
//  HandEval.hpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/21/25.
//

#ifndef HandEval_hpp
#define HandEval_hpp

#include <stdio.h>
#include "Card.hpp"

using namespace std;

namespace HandEval {
    string EvalBestHand(const vector<Card>& playerCards, const vector<Card>& riverCards);
    
}

#endif /* HandEval_hpp */
