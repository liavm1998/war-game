
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
            int rounds_won;
            int rounds_played;
            int cards_taken;

        public:
            Player(std::string name);
            int stacksize();
            int cardesTaken();
            void addCard(Card card);
            Card playCard();
            std::string turn_for_log(Card card);
            std::string get_name();
            void print_stats();
            void add_round(int cards_won);
    };
};
#endif //WAR_PLAYER_HPP