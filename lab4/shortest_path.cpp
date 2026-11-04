#include <iostream>
#include "shortest_path.h"

shortest_path_t::shortest_path_t(location_t* from, location_t*to)
    :   head {nullptr},
        base {nullptr},
        from {from},
        to {to} {

        };

shortest_path_t::~shortest_path_t() {
    node_t* curr = head;
    while (curr != nullptr) {
        node_t* nxt = curr->next;
        delete curr;
        curr = nxt;
    }
}

void shortest_path_t::compute()  {
    head = new node_t   {
        .next = nullptr,
        .location = from,
        .from = nullptr,
        .from_origin = 0.0,
        .total = from->distance_to(to),
        .visited = false
    }; 

    while (true)    {
        // Find next base
        node_t* min_node = nullptr;
        double min_total = 1e15;
        node_t* curr = head;
        while (curr != nullptr) {
            if (!curr->visited && curr->total < min_total)   {
                min_total = curr->total;
                min_node = curr;
            }
            curr = curr->next;
        }
        base = min_node; // Next base

        if (base == nullptr)    {
            return;
        }
        if (base->location == to)   {
            return;
        }
        base->visited = true;
        
        // Loop through all neighbors
        for (int i = 0; base->location->nb[i] != nullptr; i++)  {
            location_t* curr_nb = base->location->nb[i];
            double nb_dist_origin = base->from_origin + base->location->distance_to(curr_nb); // Distance from neighbor to origin, cumulatively
            double nb_dist_total = nb_dist_origin + curr_nb->distance_to(to); // Total path distance through current neighbor

            // Check if curr_nb already in head
            node_t* exist = head;
            while (exist != nullptr && exist->location != curr_nb)    {
                exist = exist->next;
            }

            // If exists
            if (exist == nullptr)   {
                node_t* new_head = new node_t   {
                    .next = head,
                    .location = curr_nb,
                    .from = base,
                    .from_origin = nb_dist_origin,
                    .total = nb_dist_total,
                    .visited = false
                };
                head = new_head;
            }

            else    {
                if (nb_dist_origin < exist->from_origin)    {
                    exist->from = base;
                    exist->from_origin = nb_dist_origin;
                    exist->total = nb_dist_total;
                    exist->visited = false;
                }
            }
        } 
    }
}

void shortest_path_t::display() {
    if (base == nullptr || base->location != to)    {
        std::cout << "unable to find a path from " << from->name << " to " << to->name << "\n";
        return;
    }

    std::cout << "path from " << from->name << " to " << to->name << "\n";
    node_t* curr = base;
    int count = 0; // Determine the length of path
    while (curr != nullptr) {
        count++;
        curr = curr->from;
    }

    // Fill the path array
    node_t** path = new node_t*[count];
    curr = base;
    for (int i = count - 1; i >= 0; i--)    {
        path[i] = curr;
        curr = curr->from;
    }

    // Iterate and print
    for (int j = 0; j < count; j++) {
        std::cout << "\t * " << path[j]->location->name << " at " << path[j]->from_origin << "km from " << from->name << "\n";
    }
    delete[] path;
}