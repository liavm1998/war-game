
#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP
#include <string>
namespace ariel{

    enum Sign{DIAMONDS,HEARTS,CLUBS,SPADES};
    class Card{
        private:
            int val;
            Sign sign;
        public:
            Card(int val, Sign sign);
            std::string print();
    };
};
#endif