#include <iostream>
#include "interpret.h"

int main()  {
    node_t* ast = new integer_t { 3 };
    std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
    return 0;
}