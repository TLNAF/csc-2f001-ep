#ifndef _SHORTEST_PATH_H
#define _SHORTEST_PATH_H
#include "location.h"
struct node_t {
    node_t* next; // Next node
    location_t* location;
    node_t* from; // Previous node
    double from_origin; // Distance from origin -> location
    double total; // Total distance to reach destination if existed a path from location
    bool visited;
};

struct shortest_path_t  {
    node_t* head; // First node
    node_t* base; // Current node
    location_t* from; // Origin
    location_t* to; // Destination

    shortest_path_t(location_t* from, location_t* to);
    void compute(); // Compute shortest path from -> to
    void display(); // Display the path, if found
};

#endif