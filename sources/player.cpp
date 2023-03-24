#include "player.hpp"
#include <string>
using namespace std;
namespace ariel{
    Player::Player(std::string name){};
    int Player::stacksize(){return 0;};
    int Player::cardesTaken(){return 0;};
    void Player::addCard(Card c){};
    Card Player::playCard(){
        Card card =  Player::hand.back();
        Player::hand.pop_back();
        return card;
    };
}