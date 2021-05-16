#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int NUM_OF_CARDS= 5;
Player &GeneSplicer::discover_cure(Color c)
{
  if(!board.has_research_station(_Curr_city)){
        throw std::invalid_argument{"illegal action: city "+city_string(_Curr_city)+" has no research station!"};
    }
    if(_cards.size() < NUM_OF_CARDS){
        throw std::invalid_argument{"illegal action: you only have "+std::to_string(_cards.size())+" "+ color_string(c) + " cards remaining " };
    }
    int count = 1;
    for(auto it = _cards.begin(); it != _cards.end(); count++){
        if(count == NUM_OF_CARDS) { break; }
        it = _cards.erase(it);
    }
    board.add_cure(c);
   
    return *this;
}