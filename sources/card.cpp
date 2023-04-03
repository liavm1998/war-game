#include "card.hpp"
#include <string>
namespace ariel{
    Card::Card(int val, Sign sign){
        this->sign=sign;
        this->val=val;
    };
    
    std::string Card::print(){
        return std::string("");
    };
};