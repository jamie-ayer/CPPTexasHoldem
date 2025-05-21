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
    folded = false;
}

void Hand::PrintHand(){
    CardArt::RenderMultCards(cardsInHand);
}

size_t Hand::CardAmount(){
    return cardsInHand.size();
}

void Hand::AddCards(const Card& card){
    cout << "Dealing card" << endl;
    cardsInHand.push_back(card);
}

void Hand::RemoveCards(){
    if(Hand::HandHasCards()){
        cardsInHand.clear();
    }
}

bool Hand::HandHasCards(){
    return !cardsInHand.empty();
}

vector<Card> Hand::GetHand(){
    return cardsInHand;
}

bool Hand::IsActive(){
    return !folded;
}

void Hand::Fold(){
    folded = true;
}

void Hand::UnFold(){
    folded = false;
}
