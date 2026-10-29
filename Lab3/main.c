#include<stdio.h>
#include "monster.h"

int main(int argc, char* argv[]) {
    char* name = "Pikachu";
    char buf[256];
    int hp = 100;
    struct monster* m[10];
    for (int i = 0; i < 10; i++)	{
    	snprintf(buf, sizeof(buf), "Pikachu-%d", i);
    	m[i] = create_monster(buf, 100);
	}
	for (int j = 0; j < 10; j++)	{
		display_monster(m[j]);
	}
	for (int k = 0; k < 10; k++)	{
		delete_monster(m[k]);
	}
    return 0;
}