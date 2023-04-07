#include "player.hpp"
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
    Player::Player(std::string name){
        this->name = name;
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
    }
    void Player::addCard(Card c){
        this->stack.push_back(c);
    }
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

    void Player::add_round(int cards_won) {
        this->rounds_played +=1;
        if(cards_won){
            this->cards_taken += cards_won;
            this->rounds_won += 1;
        }
    }
    

    void Player::print_stats(){
        cout<< "________________________________" << "\n";
        cout<< this->name << " stats report" << "\n";
        cout<< "________________________________" << "\n";
        cout << "cards_taken :"<< this->cards_taken << "\n";
        cout << "rounds_won "<< this->rounds_won << "\n";
        cout << "rounds_played "<< this->rounds_played << "\n";
        double win_rate = this->rounds_won;
        win_rate /= this->rounds_played;
        cout<< "win rate: " << win_rate << "\n";
        cout << "cards won: " << this->cards_taken <<"\n";
    }




}