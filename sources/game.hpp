#ifndef WAR_GAME_HPP
#define WAR_GAME_HPP
#include "player.hpp"

namespace ariel{
    class Game{
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