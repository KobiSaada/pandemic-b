#include "Medic.hpp"

using namespace std;
 namespace pandemic{

Player &Medic::treat(City c)
{
  if (_Curr_city != c) {
        throw std::invalid_argument{"illegal action: you are not in city " + city_string(c)};
    }
    if (board[c] == 0) {
        throw std::invalid_argument{"illegal action: no more cubes remain in city " + city_string(c)};
    }

    board[c] = 0;
    return *this;
}

    Player& Medic::drive(City c) {
        Player::drive(c);
        if (board.have_cure(c)) {
            board[c] = 0;
        }

        return *this;
    }
  Player& Medic::fly_direct(City c) {
        Player::fly_direct(c);
        if (board.have_cure(c)) {
            board[c] = 0;
        }

        return *this;
    }

    Player& Medic::fly_shuttle(City c) {
        Player::fly_shuttle(c);
        if (board.have_cure(c)) {
            board[c] = 0;
        }

        return *this;
    }
    
    Player& Medic::fly_charter(City c) {
        Player::fly_charter(c);
        if (board.have_cure(c)) {
            board[c] = 0;
        }

        return *this;
    }

 };