#include "Board.hpp"
#include <algorithm>
using namespace std;
using namespace pandemic;


   int& Board::operator[](City city) {
      return Disease_level[city];
    }
    void Board::operator=(int n) {
}

std::ostream& pandemic::operator<<(std::ostream &output, const Board &board) {
        for(const auto& t:board.Disease_level ) {
            output << "\n\nLevel of disease - \n" << "City: " << city_string(t.first) << "\nLevel: " << t.second;
        }
        output << "\n\n---------------Research Stations---------------";
        for (const auto& i: board.Research_station) {
           output << "\n" << city_string(i);
        }
        output << "\n\n---------------Cured areas---------------";
        for (const auto& i: board._curesD) {
            output << "\n" << color_string(i) << "\n";
        }

        return output;
    }





    bool Board::is_clean(){ 
        for (auto& it: Disease_level) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }


 bool Board::is_connected(City c, City c1)
{
     return Neighbors_graph.at(c).contains(c1);
}
bool Board::has_research_station(City &city)
{
    return Research_station.find(city) != Research_station.end();
}
void Board::add_research_station(City city)
{
    Research_station.insert(city);
}
void Board::add_cure(Color color)
{
    _curesD.insert(color);
}
bool Board::have_cure(const City c)
{
   
  return _curesD.count(city_color(c));

}
Color Board::city_color(City city) 
{
    return city_colors.at(city);
}
void Board::remove_cures(){
    _curesD.clear();
}


std::map<City, std::set<City>> Board::Neighbors_graph {
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};
