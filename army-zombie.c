#include<stdio.h>
#include "monster.h"
#include "army.h"
#include<stdlib.h>

struct army	{
	// Zombie army
	struct node* head;
	int cap;
	int top;
	int stars
}

struct node	{
	// Linked list of the army
	struct monster* monst;
	struct node* nxt;
}

struct army* create_army(void)	{
	// Allocating memory for an army of zomb
	struct army* a = malloc(sizeof(struct army));
	a->head = NULL;
	a->stars = 0;
	return a;
}

void add_monster_to_army(struct army* a, struct monster* m)	{
	// Add a monster to an army and extend the array if needed
	struct node* new_node = malloc(sizeof(struct node));
	new_node->monst = m;
	new_node->next = a->head;
	a->head = new_node;
}

void display_army(struct army* a)	{
	if (a == NULL)	return;
	printf("This is a %d stars army\n", a->stars);
	struct node* curr = a->head;
	while (curr != NULL)	{
		display_monster(curr->monst);
		curr = curr->next;
	}
}

void delete_army(struct army* a)	{
	if (a == NULL)	return;
	struct node* curr = a->head;
	while(curr != NULL)	{
		struct node* temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(a)
}