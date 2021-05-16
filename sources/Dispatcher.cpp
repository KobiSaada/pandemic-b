
#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
  if (_Curr_city == c) {
            throw invalid_argument("You are already in " + city_string(c));
        }
        
        if(board.has_research_station( _Curr_city )) {
        _Curr_city = c;
    }
    else {
        return Player::fly_direct(c);
    }
    return *this;
}