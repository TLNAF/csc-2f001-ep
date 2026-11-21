#include "interpret.h"
#include <string>
#include <iostream>

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
};

node_t* node_t::eval(frame_t* frame) {
  return this;
};

node_t* node_t::apply(list_t* lst, frame_t* frame) {
  error("The node is an integer or a list");
};

std::string node_t::to_string() {
  return "???";
}

bool node_t::is(std::string id) {
  return false;
}

list_t* node_t::as_list() {
  error("Cannot convert to list");
}

uintptr_t node_t::int_value() {
  error("Node is not an integer");
}

integer_t::integer_t (uintptr_t v)
  : val (v) {
      // Complex implementation
    }

std::string integer_t::to_string()  {
  return std::to_string(val);
}

uintptr_t integer_t::int_value()  {
  return val;
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

node_t* list_t::eval(frame_t* frame)  {
  node_t* first = at(0)->eval(frame); // First element
  return first->apply(this, frame);
}

keyword_t::keyword_t(std::string key)
  : id  (key) {
    // Complex implementation
  }

std::string keyword_t::to_string()  {
  return "<" + id + ">";
}

add_t::add_t()
  : keyword_t("+") {
    // Complex implementation
  }

node_t* add_t::apply(list_t* lst, frame_t* frame)  {
  uintptr_t sum = 0;
  for (size_t i = 1; i < lst->nb_elements; i++) {
    sum += lst->at(i)->eval(frame)->int_value();
  }
  integer_t* final_sum = new integer_t(sum);
  return final_sum;
}

symbol_t::symbol_t(std::string sym)
  : id  (sym) {
    // Complex implementation
  }

bool symbol_t::is(std::string id)  {
  return this->id == id;
}

std::string symbol_t::to_string() {
  return id;
}

node_t* symbol_t::eval(frame_t* frame)  {
  return frame->get(this);
}

void frame_t::set(node_t* sym, node_t* value) {
  bool found = false;
  for (size_t i = 0; i < nb_elements; i++)  {
    if (sym->is(at(i)->as_list()->at(0)->to_string())) {
      at(i)->as_list()->set_at(1, value);
      found = true;
      break;
    }
  }
  if (found == false) {
    // Creates the symbol and appends it
    list_t* pair = new list_t;
    pair->append(sym);
    pair->append(value);
    append(pair);
  } 
}

node_t* frame_t::get(node_t* sym)  {
  for (size_t i = 0; i < nb_elements; i++)  {
    if (sym->is(at(i)->as_list()->at(0)->to_string())) {
      return at(0)->as_list()->at(1);
    }
  }
  error("The symbol does not exist");
}

set_t::set_t()
  : keyword_t("set!") {
    // Complex implementation
  }

node_t* set_t::apply(list_t* lst, frame_t* frame) {
  if (lst->nb_elements != 3)  {
    error("Wrong number of arguments (must be 3)");
  }
  node_t* res = lst->at(2)->eval(frame);
  frame->set(lst->at(1), res);
  return res;
}