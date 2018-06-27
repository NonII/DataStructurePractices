
#pragma once

typedef struct slist_node {
    int data;
    struct slist_node* next;
} slist_node, *slist;

struct {
    slist(*create)(void);
    int(*get_length)(slist);
    int(*find_index)(slist, int);
    int(*get_element)(slist, int);
    void(*insert)(slist, int, int);
    void(*insert_head)(slist, int);
    void(*insert_tail)(slist, int);
    void(*delete_element)(slist, int);
    void(*traverse_list)(slist, void(*)(int));
    void(*clear)(slist);
    void(*destroy)(slist*);
    void(*inplace_revert)(slist);
} slist_operation_set;

void init_slist_operations(void);
