#include <iostream>
#include "interpret.h"

int main()  {
    /*node_t* ast = new integer_t { 3 };
    std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;*/
    list_t* ast = new list_t;

    ast->append(new integer_t { 1 });
    ast->append(new integer_t { 2 });
    ast->append(new integer_t { 3 });

    std::cout << ast->to_string() << std::endl; // should output (1 2 3)
    return 0;
}