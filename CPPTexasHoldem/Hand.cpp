//
//  Hand.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include "Hand.hpp"
#include <iostream>
#include "CardArt.hpp"

using namespace std;

Hand::Hand(){
    
}

void Hand::PrintHand(){
    CardArt::RenderMultCards(cardsInHand);
}

size_t Hand::CardAmount(){
    return cardsInHand.size();
}

void Hand::AddCards(const Card& card){
    cardsInHand.push_back(card);
}

void Hand::RemoveCards(){
    if(Hand::HandHasCards()){
        cardsInHand.clear();
    }
}

bool Hand::HandHasCards(){
    if(cardsInHand.empty()){
        return false;
    }
    return true;
}
