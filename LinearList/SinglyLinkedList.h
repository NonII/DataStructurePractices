
#pragma once

typedef struct {
	int data;
	struct singly_linked_list_node* next;
} singly_linked_list_node, *singly_linked_list;

struct {
	singly_linked_list (*create)(void);
	void (*insert)(singly_linked_list, int, int);
	void (*insert_head)(singly_linked_list, int);
	void (*insert_tail)(singly_linked_list, int);
} singly_linked_list_operation_set;

void init_singly_linked_list_operations (void);
