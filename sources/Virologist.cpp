#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{       if (_Curr_city != c) {
          if(count(_cards.begin(), _cards.end(), c) == 0) {
            throw std::invalid_argument{"illegal action: you have no card of city " + city_string(c)};
        }
      _cards.erase(remove(_cards.begin(), _cards.end(), c), _cards.end());;
    }
    else if (board[c] == 0) {
        throw std::invalid_argument{"illegal action: no more cubes remain in city " + city_string(c)};
    }
    else if (board.have_cure(c)) {
        board[c] = 0;
        return *this;
    }
    board[c]--;
    return *this;
}