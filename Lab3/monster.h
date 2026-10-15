#ifndef _MONSTER_H_
#define _MONSTER_H_
struct monster {
    int hp;
    char* name;
};

struct monster* create_monster(char* name, int hp);
void display_monster(struct monster* m);
void delete_monster(struct monster* m);

#endif