#ifndef _INTERPRET_H_
#define _INTERPRET_H_

#include <string>
#include <cstdint>
struct list_t;
void error(std::string str) __attribute__((noreturn));

struct node_t {
    virtual node_t* eval();
    virtual node_t* apply(list_t* list);
    virtual std::string to_string();
    virtual list_t* as_list();
};

struct integer_t : node_t {
    uintptr_t val;
    integer_t(uintptr_t v);
    std::string to_string();
};
#endif