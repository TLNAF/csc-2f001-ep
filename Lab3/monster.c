#include<stdio.h>
#include "monster.h"
#include <stdlib.h>

struct monster* create_monster(char* name, int hp)  {
    struct monster* m = malloc(sizeof(struct monster));
    m->hp = hp;
    m->name = name;
    return m;
}

void display_monster(struct monster* m) {
    printf("Monster: %s (HP: %d)\n", m->name ,m->hp);
}

void delete_monster(struct monster* m)  {
    free(m);
}