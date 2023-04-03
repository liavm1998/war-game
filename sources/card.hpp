
#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP
#include <string>
namespace ariel{

    enum Sign{DIAMONDS,HEARTS,CLUBS,SPADES};
    class Card{
        private:
            int val;
            Sign sign;
            std::string get_string_sign();
            std::string get_string_value();
        public:
            Card(int val, Sign sign);
            std::string to_string();
            int get_value();
    };
};
#endif