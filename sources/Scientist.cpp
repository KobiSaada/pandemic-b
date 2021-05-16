#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{   
     if(!board.has_research_station(_Curr_city)){
        throw std::invalid_argument{"illegal action: city "+city_string(_Curr_city)+" has no research station!"};
    }
    int count = 0;
    for(const auto& t : _cards){
        if(Board::city_color(t) == c) {
            count++;
        }
    }
    if(count < tmp){
        throw std::invalid_argument{"illegal action: you only have "+std::to_string(count)+" "+ color_string(c) + " cards remaining " };
    }
    count = 1;
    for(auto it = _cards.begin(); it != _cards.end(); count++){
        if(count == tmp) { break; }
        if(Board::city_color(*it) == c) {
            it = _cards.erase(it);
        }
        else {
            ++it;
        }
    }
    board.add_cure(c);
    return *this;
}