#ifndef _ARMY_H_
#define _ARMY_H_
struct army	{
	struct monster** monsters;
	int capacity;
	int top;
};

struct army* create_army(void);
void add_monster_to_army(struct army* a, struct monster* m);
void display_army(struct army* a);
void delete_army(struct army* a);

#endif