#ifndef _INTERPRET_H_
#define _INTERPRET_H_

#include <string>
#include <cstdint>
struct list_t;
void error(std::string str) __attribute__((noreturn));

struct node_t {
    virtual node_t* eval();
    virtual node_t* apply(list_t* lst);
    virtual std::string to_string();
    virtual list_t* as_list();
    virtual uintptr_t int_value();
};

struct integer_t : node_t {
    uintptr_t val;
    integer_t(uintptr_t v);
    std::string to_string();
    uintptr_t int_value();
};

struct list_t : node_t  {
    node_t** elements;
    size_t nb_elements;
    size_t capacity;
    list_t(); 
    list_t* as_list(); // Returns the list
    size_t size();
    node_t* at(size_t i); // Returns the element at the index i
    void set_at(size_t i, node_t* value); // Sets value at the index i
    void append(node_t* value);
    std::string to_string();
    node_t* eval();
};

struct keyword_t : node_t   {
    std::string id;
    keyword_t(std::string key);
    std::string to_string();
};

struct add_t : keyword_t    {
    add_t();
    node_t* apply(list_t* lst);
};
#endif