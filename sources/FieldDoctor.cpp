#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
 if (_Curr_city != c && !Board::is_connected(_Curr_city, c)) {
        throw std::invalid_argument{"illegal action: not connected " + city_string(c)};
    }
    if (board[c] == 0) {
        throw std::invalid_argument{"illegal action: no more cubes remain in city " + city_string(c)};
    }
    if (board.have_cure(c)) {
        board[c] = 0;
    }
    else {
        board[c]--;
    }
    return *this;
}