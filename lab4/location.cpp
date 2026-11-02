#include "location.h"
#include <numbers>
#include <cmath>

location_t::location_t(std::string name, double lat, double lng)
    :   name {name},
        lat {lat},
        lng {lng},   
        nb {nullptr},
        num_nb {0}  {
        // Complex implementation    
        }

location_t::~location_t()   {
    delete[] nb;
}
    
void location_t::set_neighbors(location_t* list[])  {
    nb = list;
    int i = 0;
    while (list[i] != nullptr)  i++;
    num_nb = i;
}

double location_t::distance_to(location_t* to)  {
    double lat1 = this->lat;
    double long1 = this->lng;
    double lat2 = to->lat;
    double long2 = to->lng;
    double R = 6378; // Earth's radius
    return R * (std::numbers::pi/2 - std::asin(std::sin(lat2) * std::sin(lat1) + std::cos(long2 - long1) * std::cos(lat2) * std::cos(lat1)));
}
