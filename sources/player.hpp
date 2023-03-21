
#ifndef WAR_PLAYER_HPP
#define WAR_PLAYER_HPP
#include <string>
#include <vector>
#include "card.hpp"
namespace ariel{
    class Player{
        public:
        Player(std::string name);
        int stacksize();
        int cardesTaken();
        void addCard(Card card);
        Card playCard();

        std::vector<Card> hand;
        std::string name;
    };
};

#endif //WAR_PLAYER_HPP