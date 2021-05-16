#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player &OperationsExpert::build()
{
    board.add_research_station(_Curr_city);
    return *this;
}