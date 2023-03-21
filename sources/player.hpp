
#ifndef WAR_PLAYER_HPP
#define WAR_PLAYER_HPP
#include <string>
namespace ariel{
    class Player{
        public:
        Player(std::string name);
        int stacksize();
        int cardesTaken();
    };
};

#endif //WAR_PLAYER_HPP