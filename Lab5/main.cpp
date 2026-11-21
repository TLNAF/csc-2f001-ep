#include <iostream>
#include "interpret.h"

int main()  {
    {
        node_t* ast = new integer_t { 3 };
        std::cout << ast->to_string() << " => " << ast->eval(new frame_t)->to_string() << std::endl;
    }

    {
        list_t* ast = new list_t;
        ast->append(new integer_t { 1 });
        ast->append(new integer_t { 2 });
        ast->append(new integer_t { 3 });

        std::cout << ast->to_string() << std::endl; // should output (1 2 3)*/         
    }

    {
        node_t* add = new add_t;
        list_t* ast = new list_t;

        ast->append(add);
        ast->append(new list_t);
        ast->at(1)->as_list()->append(add);
        ast->at(1)->as_list()->append(new integer_t { 1 });
        ast->at(1)->as_list()->append(new integer_t { 2 });
        ast->append(new integer_t { 3 });

        std::cout << ast->to_string() << " => " << ast->eval(new frame_t)->to_string() << std::endl;
        // should output (<+> (<+> 1 2) 3)
    }

    {
        frame_t* frame = new frame_t;

        frame->set(new symbol_t { "a" }, new integer_t { 666 });
        frame->set(new symbol_t { "b" }, new integer_t { 21 });
        frame->set(new symbol_t { "a" }, new integer_t { 42 });

        std::cout << frame->to_string() << ": a=" << frame->get(new symbol_t { "a" })->to_string() << std::endl;
    }

    {
        node_t* add = new add_t;
        symbol_t* a = new symbol_t { "a" };
        frame_t* frame = new frame_t;

        frame->set(a, new integer_t { 37 });

        list_t* ast = new list_t;

        ast->append(add);
        ast->append(new list_t);
        ast->at(1)->as_list()->append(add);
        ast->at(1)->as_list()->append(a);
        ast->at(1)->as_list()->append(new integer_t { 2 });
        ast->append(new integer_t { 3 });

        std::cout << ast->to_string() << " => " << ast->eval(frame)->to_string() << std::endl;
    }
    return 0;
}