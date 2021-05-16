#include "Player.hpp"
#include <vector>
#include <exception>
#include <algorithm>
namespace pandemic{
using namespace std;
 const int NUM_OF_CARDS = 5;

   // Player::Player(){}

    Player& Player::take_card(City city){
            _cards.insert(_cards.begin(),city);
       return *this;
    }
    
    Player& Player::drive(City city){
           if(_Curr_city == city){
        throw std::invalid_argument{"Illegal action: you already in " + city_string(city)};
    }
    if(!(Board::is_connected(_Curr_city, city))){
        throw std::invalid_argument{"Illegal action: " + city_string(city) + " is not connected to " + city_string(city)};
    }
    _Curr_city= city;
   // arrive();
    return *this;
    }
    Player& Player::fly_charter(City city){
       if(!(find(_cards.begin(), _cards.end(), _Curr_city) != _cards.end())) {
            throw invalid_argument("You don't have " + city_string(_Curr_city) + " in your cards");
        }
        if (_Curr_city== city) {
            throw invalid_argument("You are already in " + city_string(city));
        }
        _cards.erase(remove(_cards.begin(), _cards.end(), _Curr_city), _cards.end());
        _Curr_city = city;
        
        return *this;
    }
    Player& Player::fly_direct(City city){
      if(count(_cards.begin(), _cards.end(), city) == 0) {
            throw invalid_argument("You don't have " + city_string(city) + " in your cards");
        }
        if (_Curr_city == city) {
            throw invalid_argument("You are already in " + city_string(city));
        }
        _cards.erase(remove(_cards.begin(), _cards.end(), city), _cards.end());
        _Curr_city = city;
        
        return *this;
    }
    Player& Player::fly_shuttle(City city){
        if(_Curr_city == city){
        throw std::invalid_argument{"Illegal action: you already in " + city_string(city)};
    }
    if(!board.has_research_station(_Curr_city) || !board.has_research_station(city)){
        throw std::invalid_argument{"Illegal action: " + city_string(city) + " and " + city_string(city) + " must both have research station."};
    }
    _Curr_city = city;
    //arrive();
    return *this;
}
    Player& Player::build(){
           if(!(find(_cards.begin(), _cards.end(), _Curr_city) != _cards.end())) {
        throw std::invalid_argument{"Cant build research station! the player dont have a " + city_string(_Curr_city) + " card"};
    }
    board.add_research_station(_Curr_city);
    _cards.erase(remove(_cards.begin(), _cards.end(), _Curr_city), _cards.end());
    return *this;
}
    Player& Player::discover_cure(Color color){
    if(!board.has_research_station(_Curr_city)){
        throw std::invalid_argument{"illegal action: city "+city_string(_Curr_city)+" has no research station!"};
    }
    int count = 0;
    for(const auto& t : _cards){
        if(Board::city_color(t) == color) {
            count++;
        }
    }
    if(count < NUM_OF_CARDS){
        throw std::invalid_argument{"illegal action: you only have "+std::to_string(count)+" "+ color_string(color) + " cards remaining " };
    }
    count = 1;
    for(auto it = _cards.begin(); it != _cards.end(); count++){
        if(count == NUM_OF_CARDS) { break; }
        if(Board::city_color(*it) == color) {
            it = _cards.erase(it);
        }
        else {
            ++it;
        }
    }
    board.add_cure(color);
    return *this;
}
    Player& Player::treat(City city){
    if (_Curr_city!= city) {
        throw std::invalid_argument{"illegal action: you are not in city " + city_string(city)};
    }
    if (board[city] == 0) {
        throw std::invalid_argument{"illegal action: no more cubes remain in city " + city_string(city)};
    }
    if (board.have_cure(city)) {
        board[city] = 0;
    }
    else {
        board[city]--;
    }
    return *this;
}
    
};