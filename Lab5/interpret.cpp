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
  error("Cannot convert to list");
}

integer_t::integer_t (uintptr_t v)
  : val (v) {
      // Complex implementation
    }

std::string integer_t::to_string()  {
  return std::to_string(val);
}

list_t::list_t()
  : elements  (nullptr),
    nb_elements (0),
    capacity  (0) {
      // Complex implementation
    }

list_t* list_t::as_list() {
  return this;
}

size_t list_t::size() {
  return nb_elements;
}

node_t* list_t::at(size_t i)  {
  if (i >= nb_elements) {
    error("Index error");
  }
  return elements[i];
}

void list_t::set_at(size_t i, node_t* value)  {
  if (i >= nb_elements) {
    error("Index error");
  }
  elements[i] = value;
}

void list_t::append(node_t* value)  {
  if (nb_elements == capacity)  { // Allocate more capacity once the old capacity is reached
    node_t** new_elements = new node_t*[2*capacity + 1];
    for (size_t i = 0; i < nb_elements; i++) {
      new_elements[i] = elements[i];
    }
    elements = new_elements;
    capacity = 2*capacity + 1;
  }
  nb_elements++;
  set_at(nb_elements - 1, value);
}

std::string list_t::to_string() {
  std::string s = "(";
  for (size_t i = 0; i < nb_elements; i++) {
    s += elements[i]->to_string();
    if (i < nb_elements - 1)  {
      s += " ";
    }
  }
  return s + ")";
}