
#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int NUM_OF_CARDS= 5;
Player &Researcher::discover_cure(Color c)
{
    int count = 0;
    for(const auto& t : _cards){
        if(Board::city_color(t) == c) {
            count++;
        }
    }
    if(count < NUM_OF_CARDS ){
        throw std::invalid_argument{"illegal action: you only have "+std::to_string(count)+" "+ color_string(c) + " cards remaining " };
    }
    count = 1;
    for(auto it = _cards.begin(); it != _cards.end(); count++){
        if(count == NUM_OF_CARDS) { break; }
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