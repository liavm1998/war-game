#ifndef WAR_GAME_HPP
#define WAR_GAME_HPP
#include "player.hpp"
#include "card.hpp"

namespace ariel{
    class Game{
        private:
            Player& p1;
            Player& p2;
            std::vector<std::string> logs;
            int draws;
            int rounds;
        public:
        Game(Player& p1, Player& p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
};
#endif