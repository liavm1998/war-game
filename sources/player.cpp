#include "player.hpp"
#include "card.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel{

    
    Player::Player(std::string name){
        this->name = name;
        // if(!this->hand.empty()){
        //     throw "player already playing";
        // }
        this->stack.clear();
        this->cards_taken = 0;
        this->rounds_played = 0;
        this->rounds_won = 0;
    };

    int Player::stacksize(){
        return stack.size();
    };
    int Player::cardesTaken()
    {
        return this->cards_taken;
    };
    void Player::addCard(Card c){
        this->stack.push_back(c);
    };
    Card Player::playCard(){
        Card card =  Player::stack.back();
        Player::stack.pop_back();
        return card;
    };

    std::string Player::turn_for_log(Card card){
        return this->name + " played " + card.to_string();
    }
    std::string Player::get_name(){
        return this->name;
    }

    void Player::round_win(int card_won){
        this->cards_taken += card_won;
        this->rounds_played++;
    }
    
    void Player::add_round(int didwon){
        this->rounds_played++;
    }
    void Player::print_stats(){
        cout<< this->name << " stats report" << "\n";
        cout<< "________________________________";
        cout<< "win rate: " << (this->rounds_won/this->rounds_played) << "\n";
        cout << "cards won: " << this->cards_taken <<"\n";
    }
}