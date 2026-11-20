#include "interpret.h"
#include <string>
#include <iostream>

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
};

node_t* node_t::eval()  {
  return this;
};

node_t* node_t::apply(list_t* list) {
  error("The node is an integer or a list");
};

std::string node_t::to_string() {
  return "???";
}

list_t* node_t::as_list() {
  error("Cannot convert to the list");
}

integer_t::integer_t (uintptr_t v)
  : val (v) {
      // Complex implementation
    }

std::string integer_t::to_string()  {
  return std::to_string(val);
}