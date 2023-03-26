
#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP
#include <string>
namespace ariel{
    class Card{
        public:
        Card(int val, char sign);
        std::string print();
    };
};
#endif