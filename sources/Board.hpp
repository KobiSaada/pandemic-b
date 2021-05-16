#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <stdexcept>
#include <algorithm>

namespace pandemic
{
    class Board
    {

    static std::map<City, std::set<City>> Neighbors_graph;
    std::map<City, int> Disease_level;
    std::set<Color> _curesD;
   // std::map<City, Color> city_colors;
    std::set<City> Research_station;
    //bool _cured[4]={};


    public:
        Board(){};
         void operator=(int n);
        int& operator[](City c);
        friend std::ostream &operator<<(std::ostream &output, const Board &board);
        bool is_clean();
        
        void remove_cures();
        bool has_research_station( City&c);
       static bool is_connected( City c,  City c1);
       static Color city_color(City c);
        void add_research_station(City city);
         bool have_cure(const City c);
         void add_cure(Color color);
          const std::map<std::string,City> cities_names = {
            {"Algiers",City::Algiers},
            {"Atlanta",City::Atlanta},
            {"Baghdad",City::Baghdad},
            {"Bangkok",City::Bangkok},
            {"Beijing",City::Beijing},
            {"Bogota",City::Bogota},
            {"BuenosAires",City::BuenosAires},
            {"Cairo",City::Cairo},
            {"Chennai",City::Chennai},
            {"Chicago",City::Chicago},
            {"Delhi",City::Delhi},
            {"Essen",City::Essen},
            {"HoChiMinhCity",City::HoChiMinhCity},
            {"HongKong",City::HongKong},
            {"Istanbul",City::Istanbul},
            {"Jakarta",City::Jakarta},
            {"Johannesburg",City::Johannesburg},
            {"Karachi",City::Karachi},
            {"Khartoum",City::Khartoum},
            {"Kinshasa",City::Kinshasa},
            {"Kolkata",City::Kolkata},
            {"Lagos",City::Lagos},
            {"Lima",City::Lima},
            {"London",City::London},
            {"LosAngeles",City::LosAngeles},
            {"Madrid",City::Madrid},
            {"Manila",City::Manila},
            {"MexicoCity",City::MexicoCity},
            {"Miami",City::Miami},
            {"Milan",City::Milan},
            {"Montreal",City::Montreal},
            {"Moscow",City::Moscow},
            {"Mumbai",City::Mumbai},
            {"NewYork",City::NewYork},
            {"Osaka",City::Osaka},
            {"Paris",City::Paris},
            {"Riyadh",City::Riyadh},
            {"SanFrancisco",City::SanFrancisco},
            {"Santiago",City::Santiago},
            {"SaoPaulo",City::SaoPaulo},
            {"Seoul",City::Seoul},
            {"Shanghai",City::Shanghai},
            {"StPetersburg",City::StPetersburg},
            {"Sydney",City::Sydney},
            {"Taipei",City::Taipei},
            {"Tehran",City::Tehran},
            {"Tokyo",City::Tokyo},
            {"Washington",City::Washington},
        };
        const std::map<std::string,Color> colors_names = {
            {"Black",Color::Black},
            {"Blue",Color::Blue},
            {"Red",Color::Red},
            {"Yellow",Color::Yellow},
        };
    };
   
    };


