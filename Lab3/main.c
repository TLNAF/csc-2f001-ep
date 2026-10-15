#include<stdio.h>
#include "monster.h"

int main(int argc, char* argv[]) {
    char* name = "Pikachu";
    int hp = 100;
    struct monster* m = create_monster(name, hp);
    display_monster(m);
    delete_monster(m);
    return 0;
}