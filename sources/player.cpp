#include "player.hpp"
#include <string>
using namespace std;
namespace ariel{
    Player::Player(std::string name){};
    int Player::stacksize(){return 0;};
    int Player::cardesTaken(){return 0;};
    void Player::addCard(Card c){};
    Card Player::playCard(){
        return Card(1,'A');
    };
}