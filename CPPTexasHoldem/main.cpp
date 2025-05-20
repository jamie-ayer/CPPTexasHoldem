//
//  main.cpp
//  CPPTexasHoldem
//
//  Created by Jamie on 5/20/25.
//

#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Table.hpp"
#include <string>

using namespace std;

void TestBasicDeckAndHand();
void PrintMenu();
void PlayGame();



int main(int argc, const char * argv[]) {
    
    char inp;
    
    Table table = Table();
    Hand playerHand = Hand();
    
    
    PrintMenu();
    cin >> inp;
    
    while(inp != 'q'){
        if(inp == 's'){
            PlayGame();
        }
    }
    
    playerHand.AddCards(table.gameDeck.DealSingleCard());
    playerHand.AddCards(table.gameDeck.DealSingleCard());
    
    table.RenderRiver();
    
    table.AddCardToRiver();
    
    table.RenderRiver();
    
    while(inp != 'q'){
        PrintMenu();
        cin >> inp;
    }

    
    return 0;
}

void TestBasicDeckAndHand(){
    cout << "Creating Deck()\n" << endl;
    Deck deck = Deck();
    Hand playerHand = Hand();
    
    cout << "Deck created, printing deck\n" << endl;
    
    deck.PrintDeck();
    deck.Shuffle();
    deck.PrintDeck();
    
    cout << "\nTesting player hand\nCards in hand: " << playerHand.CardAmount() << endl;
    cout << "Player has cards: " << playerHand.HandHasCards() << endl;
    cout << "Adding cards to player hand" << endl;
    
    playerHand.AddCards(deck.DealSingleCard());
    playerHand.AddCards(deck.DealSingleCard());
    
    cout << "\nTesting player hand\nCards in hand: " << playerHand.CardAmount() << endl;
    cout << "Player has cards: " << playerHand.HandHasCards() << endl;
    
    cout << "Testing card rendering" << endl;
    
    playerHand.PrintHand();

}

void PrintMenu(){
    cout << "TEXAS HOLDEM\n\n" << endl;
    cout << "    MENU" << endl;
    cout << "s - Start Game" << endl;
    cout << "q - Quit" << endl;
}
