#include "game.hpp"
#include <algorithm>
#include <iostream>
namespace ariel{
using namespace std;


Game::Game(Player& p1, Player& p2): p1(p1),p2(p2){
    vector<Card> deck;
    // Create all 52 cards and add them to the deck
    for (int i = 1; i <= 13; i++) {
        deck.push_back(Card(i, SPADES)); // Spades
        deck.push_back(Card(i, HEARTS)); // Hearts 
        deck.push_back(Card(i, DIAMONDS)); // Diamonds 
        deck.push_back(Card(i, CLUBS)); // Clubs 
    }
    srand(time(NULL)); 
    random_shuffle(deck.begin(), deck.end());
    // Deal 26 cards each to both players 
   for (unsigned long int i = 0; i < 26; i++) {
    p1.addCard(deck[i]);
    p2.addCard(deck[i + 26]);
   }
};
    
        
        
        
    void Game::playTurn()
    {
        if(this->p1.stacksize() == 0){
            throw "error";
        }
        std::string log = "";
        int cont = 1;
        int cards_won = 0;
        while (cont){  
            this->rounds++;
            cont = 0;
            // getting the cards
            Card p1card = this->p1.playCard();
            Card p2card = this->p2.playCard();
            cards_won+=2;
            // setting the first part of the log;
            log += p1.turn_for_log(p1card) + " " + p2.turn_for_log(p2card) + ". ";
            // find the winner
            
            // draw case
            if(p1card.get_value() == p2card.get_value())
            {
                cont = 1;
                log += "Draw.";
                //for poping
                this->p1.playCard();
                this->p2.playCard();
                cards_won+=2;
                this->draws++;
            }
            //  ace wins against all except for 2 cases
            else if(p1card.get_value() == 1 && p2card.get_value() != 2)
            {
                log += this->p1.get_name() + " wins.";
                p1.round_win(cards_won);
            }
            else if(p1card.get_value() != 2 && p2card.get_value() == 1)
            {
                log += this->p2.get_name() + " wins.";
                p2.round_win(cards_won);
            }   
            
            // default case by value
            else if (p1card.get_value() > p2card.get_value()){
                log += this->p1.get_name() + " wins.";
                p1.round_win(cards_won);
            }
            else if (p2card.get_value() > p1card.get_value()){
                log += this->p2.get_name() + " wins.";
                p2.round_win(cards_won);
            }
        }
        log+="\n"; // round end
        this->logs.push_back(log);
    };
    
    void Game::printLastTurn()
    {
        cout << "******************liav*********************";
        cout << this->logs.back();
        cout << "*******************************************";
        cout << this->logs.back(); 
    };
    void Game::playAll(){
        while (this->p1.stacksize() > 0)
        {
            playTurn();
        }
    };
    void Game::printWiner(){
        if(p1.cardesTaken() > p2.cardesTaken()){
            cout << p1.get_name() + " won";
        }
        if(p1.cardesTaken() < p2.cardesTaken()){
            cout << p1.get_name() + " won";
        }
        else
            throw "no winner";
    };
    void Game::printLog(){
        for(std::string log : this->logs){
            cout << log;
        }
    };
    void Game::printStats(){
        this->p1.print_stats();
        this->p2.print_stats();
        double draw_rate = this->draws/this->rounds;
        cout << "game stats";
        cout << "______________________";
        cout << "draw rate:" << draw_rate <<"\n";
        cout << "draws amount:" << this->draws << "\n";
    };

};