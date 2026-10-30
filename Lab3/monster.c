#include<stdio.h>
#include "monster.h"
#include "macro.h"
#include <stdlib.h>

struct monster* create_monster(char name[256], int hp)  {
    struct monster* m = malloc(sizeof(struct monster));
    m->hp = hp;
    snprintf(m->name, NAME_SIZE, "%s", name);
    return m;
}

void display_monster(struct monster* m) {
    printf("Monster: %s (HP: %d)\n", m->name ,m->hp);
}

void delete_monster(struct monster* m)  {
    free(m);
}