#include "player.hpp"
#include "card.hpp"
#include <string>
using namespace std;
namespace ariel{

    
    Player::Player(std::string name){
        this->name = name;
        // if(!this->hand.empty()){
        //     throw "player already playing";
        // }
        this->stack.clear();
        this->cards_taken=0;
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
}