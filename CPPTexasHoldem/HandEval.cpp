//
//  HandEval.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/21/25.
//

#include "HandEval.hpp"
#include "Card.hpp"
#include "CardArt.hpp"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

string HandEval::EvalBestHand(const vector<Card> &playerCards, const vector<Card> &riverCards){
    
    /**************************************** INIT RANK AND SUIT MAPS, INIT TEMP VECTOR FOR HAND AND RIVER CARDS**********************************************************************************/
    
    // Maps to hold rank and suit counts
    unordered_map<Card::CardValue, int> valueAmountsMap;
    unordered_map<Card::CardValue, Card::Suit> suitForRankMap;
    
    // TODO: decide bestHand use or temp card return
    vector<Card> bestHand;
    
    string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    // Sets CardsToEval to the passed player hand, then river cards it there are any
    vector<Card> cardsToEval = playerCards;
    if(!riverCards.empty())
        cardsToEval.insert(cardsToEval.begin(), riverCards.begin(), riverCards.end());
    
    
    /****************************************SETUP FOR FLUSH DETECTION**********************************************************************************/
    
    unordered_map<Card::Suit, vector<Card>> suitBuckets;

    for(const Card& card : cardsToEval) {
        suitBuckets[card.GetSuit()].push_back(card);
    }
    
    /****************************************START OF STRAIGHT DETECTION**********************************************************************************/
    vector<int> uniqueRanks;

    for(const Card& card : cardsToEval) {
        int val = static_cast<int>(card.GetCardVal());
        if(find(uniqueRanks.begin(), uniqueRanks.end(), val) == uniqueRanks.end()) {
            uniqueRanks.push_back(val);
        }
    }

    // CHECK LOW ACE
    if(find(uniqueRanks.begin(), uniqueRanks.end(), 14) != uniqueRanks.end()) {
        uniqueRanks.push_back(1);
    }
    // SORT POTENTIAL STRAIGHT
    sort(uniqueRanks.begin(), uniqueRanks.end());
    
    int consecutive = 1;
    int maxStart = -1;

    for(size_t i = 1; i < uniqueRanks.size(); ++i) {
        if(uniqueRanks[i] == uniqueRanks[i - 1] + 1) {
            consecutive++;
            if(consecutive >= 5) {
                // GET WHERE FIVE CARD STRAIGHT STARTS
                maxStart = uniqueRanks[i - 4];
            }
        } 
        else{
            consecutive = 1;
        }
    }
    
    /****************************************KEEPS TRACK OF SUITS PER RANK**********************************************************************************/
    /************************ CANT USE CARD OBJ TO PASS AROUND WITH HOW THE COMPARING WORKS********************************************************/
    
    // counts how many of each rank there are, and keeps the suit in the suit map
    for(const Card& card : cardsToEval) {
        valueAmountsMap[card.GetCardVal()]++;

        if(suitForRankMap.find(card.GetCardVal()) == suitForRankMap.end()) {
            suitForRankMap[card.GetCardVal()] = card.GetSuit();  // track one suit per rank, this is for card arscii art and flushes
        }
    }
    
    /**************************************** HIGHCARD, PAIRS  DETECTION**********************************************************************************/
    int amount = 0;
    Card::CardValue highestRank = Card::CardValue::TWO;  // lowest default value to start
    Card::CardValue tripsRank = Card::CardValue::TWO;
    Card::CardValue pairRank = Card::CardValue::TWO;
    bool hasTrips = false;
    vector<Card::CardValue> pairs;
    
    // HIGHCARD, PAIR, TWO PAIR, THREE PAIR
    for(const auto& [rank, count] : valueAmountsMap) {
        if(count > amount || (count == amount && static_cast<int>(rank) > static_cast<int>(highestRank))) {
            amount = count;
            highestRank = rank;
        }
        // COUNTS TWO PAIR
        if(count >= 2) {
            pairs.push_back(rank);
        }
        // THREE PAIR
        if(count == 3) {
            if(!hasTrips || static_cast<int>(rank) > static_cast<int>(tripsRank)) {
                tripsRank = rank;
                hasTrips = true;
            }
        }
    }
    
    /**************************************** PAIR FOR FULL HOUSE DETECTION**********************************************************************************/
    // PAIR FOR FULL HOUSE DETECTION
    bool hasPair = false;
    
    for(const auto& [rank, count] : valueAmountsMap) {
        if(rank != tripsRank && count >= 2) {
            if(!hasPair || static_cast<int>(rank) > static_cast<int>(pairRank)) {
                pairRank = rank;
                hasPair = true;
            }
        }
    }
    
    /**************************************** FOUR OF A KIND DETECTION**********************************************************************************/
    // FOUR OF A KIND DETECTION
    Card::CardValue quadsRank = Card::CardValue::TWO;
    bool hasQuads = false;

    for(const auto& [rank, count] : valueAmountsMap) {
        if(count == 4) {
            if(!hasQuads || static_cast<int>(rank) > static_cast<int>(quadsRank)) {
                quadsRank = rank;
                hasQuads = true;
            }
        }
    }
    
    /**************************************** FLUSH DETECTION**********************************************************************************/
    // FLUSH DETECTION
    for (const auto& [suit, cards] : suitBuckets) {
        if (cards.size() >= 5) {
            // SORT FLUSH CARDS
            vector<Card> flushCards = cards;
            sort(flushCards.begin(), flushCards.end(), [](const Card& a, const Card& b) {
                return static_cast<int>(a.GetCardVal()) > static_cast<int>(b.GetCardVal());
            });

            string bestStr = "Flush: ";
            for(int i = 0; i < 5; i++) {
                bestStr += flushCards[i].ToString() + " ";
            }
            return bestStr;
        }
    }
    
    /**************************************** FORMATING**********************************************************************************/
    // High Card if no pairs
    if(amount < 2) {
        return "High Card: " + CardArt::FormatCardAscii(highestRank, suitForRankMap[highestRank]);
    }
    // Full House
    else if(hasTrips && hasPair) {
        string bestStr = "Full House: ";
        for(int i = 0; i < 3; ++i) {
            bestStr += CardArt::FormatCardAscii(tripsRank, suitForRankMap[tripsRank]) + " ";
        }
        for(int i = 0; i < 2; ++i) {
            bestStr += CardArt::FormatCardAscii(pairRank, suitForRankMap[pairRank]) + " ";
        }
        return bestStr;
    }
    // Four of a kind
    else if(hasQuads) {
        string bestStr = "Four of a Kind: ";
        for(int i = 0; i < 4; ++i) {
            bestStr += CardArt::FormatCardAscii(quadsRank, suitForRankMap[quadsRank]) + " ";
        }

        // Show Kicker
        Card::CardValue bestKicker = Card::CardValue::TWO;
        for(const auto& [rank, count] : valueAmountsMap) {
            if (rank != quadsRank && static_cast<int>(rank) > static_cast<int>(bestKicker)) {
                bestKicker = rank;
            }
        }

        bestStr += "|Kicker: " + CardArt::FormatCardAscii(bestKicker, suitForRankMap[bestKicker]) + "|";
        return bestStr;
    }
    // STRAIGHT FORMAT
    else if(maxStart != -1) {
        string bestStr = "Straight: ";
        for(int i = 0; i < 5; ++i) {
            Card::CardValue val = static_cast<Card::CardValue>(maxStart + i);
            Card::Suit suit = suitForRankMap[val];
            bestStr += CardArt::FormatCardAscii(val, suit) + " ";
        }
        return bestStr;
    }
    // format for triple
    else if(hasTrips) {
        string bestStr = "Three of a Kind: ";
        for(int i = 0; i < 3; ++i) {
            bestStr += CardArt::FormatCardAscii(tripsRank, suitForRankMap[tripsRank]) + " ";
        }
        return bestStr;
    }
    // Format output for two pair
    else if(pairs.size() >= 2) {
        string bestStr = "Two Pair: ";
        for(int i = 0; i < 2; ++i) {
            Card::CardValue rank = pairs[i];
            Card::Suit suit = suitForRankMap[rank];
            bestStr += CardArt::FormatCardAscii(rank, suit) + " ";
            bestStr += CardArt::FormatCardAscii(rank, suit) + " ";
        }
        return bestStr;
    }
    // Single Pair
    else{
        string bestStr = "Pair of: ";
        for(int i = 0; i < amount; ++i) {  // Repeat as many times as matched cards
            bestStr += CardArt::FormatCardAscii(highestRank, suitForRankMap[highestRank]) + " ";
        }
        return bestStr;
    }
}
