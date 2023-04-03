
#ifndef WAR_PLAYER_HPP
#define WAR_PLAYER_HPP
#include <string>
#include <vector>
#include "card.hpp"
namespace ariel{
    class Player{
        private:
            std::vector<Card> stack;
            std::string name;
            int cards_taken;

        public:
            Player(std::string name);
            int stacksize();
            int cardesTaken();
            void addCard(Card card);
            Card playCard();
    };
};
#endif //WAR_PLAYER_HPP