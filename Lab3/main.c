#include<stdio.h>
#include "monster.h"
#include "macro.h"
#include "army.h"

int main(int argc, char* argv[]) {
    char* name = "Pikachu";
    char buf[NAME_SIZE];
    int hp = 100;
    struct monster* m[10];
    struct army* a = create_army();
    for (int i = 0; i < 10; i++)	{
    	snprintf(buf, sizeof(buf), "Pikachu-%d", i);
    	m[i] = create_monster(buf, 100);
    	add_monster_to_army(a, m[i]);
	}
	display_army(a);
	for (int k = 0; k < 10; k++)	{
		delete_monster(m[k]);
	}
	delete_army(a);
    return 0;
}