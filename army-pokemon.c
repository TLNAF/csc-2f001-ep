#include<stdio.h>
#include "monster.h"
#include "army.h"
#include<stdlib.h>

struct army	{
	// Army of pokemon
	struct monster** monsters;
	int cap;
	int top;
};

struct army* create_army(void)	{
	// Create an army of pokemon
	struct army* a = malloc(sizeof(struct army));
	a->monsters = NULL;
	a->top = 0;
	a->capacity = 0;
	return a;
}

void add_monster_to_army(struct army* a, struct monster* m)	{
	// Add a monster to the army and extend if needed
	if (a->top >= a->capacity)	{
		int new_cap = (a->cap == 0) ? 1 : a->cap * 2;
		struct monster** new_m = realloc(a->monsters, new_cap * sizeof(struct monster*));
		a->monsters = new_m;
		a->cap = new_cap;
	}
	a->monsters[a->top] = m;
	a->top++;
}

void display_army(struct army* a)	{
	for (int i = 0; i < a->top; i++)	{
		display_monster(a->monsters[i]);
	}
}

void delete_army(struct army* a)	{
	free(a->monsters);
	free(a);
}