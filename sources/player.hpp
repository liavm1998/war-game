
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


            /////// for make tidy
            // destructor
            ~Player(){
                stack.shrink_to_fit();
                stack.clear();
            }
            //// copy constructor
            Player(const Player& other);
            /////// copy opertator
            Player& operator=(Player other){
                std::swap(name, other.name);
                return *this;
            };
            ///// move constructor
            Player(const Player&& other) noexcept{
                this->name = "demo";
                this->stack.clear();
                this->rounds_played=0;
                this->rounds_won=0;
                this->cards_taken=0;
            };
            ///// move assigment operator
            Player& operator=(Player&& other) noexcept{
                return *this;
            };

    };
};
#endif //WAR_PLAYER_HPP