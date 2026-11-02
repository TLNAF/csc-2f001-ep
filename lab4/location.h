#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <string>
struct location_t   {
    std::string name;
    double lat; // Latitude
    double lng; // Longitude
    location_t** nb; // Neighbors list
    int num_nb; // Number of neighbors

    location_t(std::string name, double lat, double lng);
    ~location_t();
    
    void set_neighbors(location_t* list[]);
    double distance_to(location_t* to);
};

#endif