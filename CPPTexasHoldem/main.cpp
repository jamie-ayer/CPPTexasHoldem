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
#include "HandEval.hpp"
#include "Table.hpp"
#include <string>

using namespace std;

void PrintMenu();
void PlayGame();
char GetInput();
void TestGame();
void RenderGame(Hand& hand, Table& table);

int main(int argc, const char * argv[]) {
    
    char inp;
    
    PrintMenu();
    cin >> inp;
    
    while(inp != 'q'){
        if(inp == 's')
            PlayGame();
        if(inp == 't')
            TestGame();
        PrintMenu();
        cin >> inp;
    }

    return 0;
}

void PrintMenu(){
    cout << "TEXAS HOLDEM\n\n" << endl;
    cout << "    MENU" << endl;
    cout << "s - Start Game" << endl;
    cout << "t - Test" << endl;
    cout << "q - Quit" << endl;
}

void PlayGame(){
    
    char inp;
    cout << "STARTING GAME\n\n" << endl;
    Table table = Table();
    Hand playerHand = Hand();
    
    for(int round = 0; round < 5; round++){
        while(playerHand.CardAmount() < 2){
            playerHand.AddCards(table.DealCard());
        }
        
        cout << "----------------ROUND" << round + 1 << "--------------------" << endl;
        RenderGame(playerHand, table);
        inp = GetInput();
        if(inp == 'q')
            break;
        
        while(inp == 's'){
            if(table.RiverAmount() < 3){
                table.AddCardToRiver(3);
            }
            else if(table.RiverAmount() < 5){
                table.AddCardToRiver();
            }
            
            
            cout << "----------------ROUND" << round + 1 << "--------------------" << endl;
            RenderGame(playerHand, table);
            inp = GetInput();
            if(inp == 'f'){
                cout << "FOLDING HAND" << endl;
                playerHand.Fold();
            }
            if(inp == 'q')
                break;
        }
        
        cout << "CLEARING BOARD" << endl;
        table.AddCardsToDiscardPile(playerHand.GetHand());
        playerHand.RemoveCards();
        table.RemoveCardsFromRiver();
        if(playerHand.IsActive() == false)
            playerHand.Fold();
    }
}

char GetInput(){
    char inp;
    cout << "s - STAY | f - FOLD | q - QUIT" << endl;
    cin >> inp;
    return inp;
}

void RenderGame(Hand& hand, Table& table){
    table.RenderRiver();
    cout << HandEval::EvalBestHand(hand.GetHand(), table.GetRiverCards()) << endl;
    hand.PrintHand();
}

void TestGame() {
    cout << "STARTING TEST\n\n" << endl;

    // Pause between tests
    auto Wait = []() {
        cout << "\nPress any key to continue...\n";
        cin.ignore();
        cin.get();
    };

    // -------- High Card --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::KING));
        hand.AddCards(Card(Card::Suit::HEARTS, Card::CardValue::NINE));
        

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::FIVE),
            Card(Card::Suit::SPADES, Card::CardValue::SEVEN),
            Card(Card::Suit::HEARTS, Card::CardValue::JACK),
            Card(Card::Suit::CLUBS, Card::CardValue::THREE)
        };
        
        table.AddCardsToRiver(river);

        cout << "[Test: High Card]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }

    // -------- One pair --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));
        hand.AddCards(Card(Card::Suit::HEARTS, Card::CardValue::NINE));

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::FIVE),
            Card(Card::Suit::SPADES, Card::CardValue::SEVEN),
            Card(Card::Suit::HEARTS, Card::CardValue::JACK),
            Card(Card::Suit::CLUBS, Card::CardValue::THREE)
        };
        
        table.AddCardsToRiver(river);

        cout << "[Test: One Pair]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }
    
    // -------- Two pair --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));
        hand.AddCards(Card(Card::Suit::HEARTS, Card::CardValue::NINE));

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::FIVE),
            Card(Card::Suit::SPADES, Card::CardValue::SEVEN),
            Card(Card::Suit::HEARTS, Card::CardValue::JACK),
            Card(Card::Suit::CLUBS, Card::CardValue::SEVEN)
        };
        
        table.AddCardsToRiver(river);

        cout << "[Test: Two Pair]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }

    // -------- Three pair --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));
        hand.AddCards(Card(Card::Suit::HEARTS, Card::CardValue::THREE));

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::FIVE),
            Card(Card::Suit::SPADES, Card::CardValue::JACK),
            Card(Card::Suit::HEARTS, Card::CardValue::JACK),
            Card(Card::Suit::CLUBS, Card::CardValue::JACK)
        };
        table.AddCardsToRiver(river);

        cout << "[Test: Three Pair]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }
    
    // -------- Full House --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));
        hand.AddCards(Card(Card::Suit::HEARTS, Card::CardValue::NINE));

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::FIVE),
            Card(Card::Suit::SPADES, Card::CardValue::JACK),
            Card(Card::Suit::HEARTS, Card::CardValue::JACK),
            Card(Card::Suit::CLUBS, Card::CardValue::JACK)
        };
        
        table.AddCardsToRiver(river);

        cout << "[Test: Full House]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }
    
    // -------- FOUR OF A KIND --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));
        hand.AddCards(Card(Card::Suit::HEARTS, Card::CardValue::NINE));

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::JACK),
            Card(Card::Suit::SPADES, Card::CardValue::JACK),
            Card(Card::Suit::HEARTS, Card::CardValue::JACK),
            Card(Card::Suit::CLUBS, Card::CardValue::JACK)
        };
        
        table.AddCardsToRiver(river);

        cout << "[Test: FOUR OF A KIND]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }
    
    // -------- FLUSH --------
    {
        Table table;
        Hand hand;
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));
        hand.AddCards(Card(Card::Suit::SPADES, Card::CardValue::NINE));

        vector<Card> river = {
            Card(Card::Suit::CLUBS, Card::CardValue::TWO),
            Card(Card::Suit::DIAMONDS, Card::CardValue::FIVE),
            Card(Card::Suit::SPADES, Card::CardValue::JACK),
            Card(Card::Suit::SPADES, Card::CardValue::FOUR),
            Card(Card::Suit::SPADES, Card::CardValue::JACK)
        };
        
        table.AddCardsToRiver(river);

        cout << "[Test: Flush]" << endl;
        table.RenderRiver();
        hand.PrintHand();
        cout << HandEval::EvalBestHand(hand.GetHand(), river) << endl;
        Wait();
    }
}

