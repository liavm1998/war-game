#include "card.hpp"
#include <string>
namespace ariel{
    Card::Card(){ // default constructor for myself
        this->sign=HEARTS;
        this->val=-1;
    };
    Card::Card(int val, Sign sign){
        this->sign=sign;
        this->val=val;
    };
    std::string Card::get_string_value(){
        if (this->val == 1){return "ace";}
        if (this->val == 11){return "Prince";}
        if (this->val == 12){return "Queen";}
        if (this->val == 13){return "King";}
        return std::to_string(this->val);
    };
    std::string Card::get_string_sign(){
        std::string sign;
        switch (this->sign){
        case DIAMONDS: return "Diamonds";
        case SPADES: return "Spades";
        case HEARTS: return "Hearts";
        default: return "Clubs";
        }
    };

    std::string Card::to_string(){
        return get_string_value() +" of " + get_string_sign();
    };

    int Card::get_value(){
        return this->val;
    }
};