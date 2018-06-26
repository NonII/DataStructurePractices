
#pragma once

typedef struct singly_linked_list_node {
    int data;
    struct singly_linked_list_node* next;
} singly_linked_list_node, *singly_linked_list;

struct {
    singly_linked_list(*create)(void);
    int(*get_length)(singly_linked_list);
    int(*find_index)(singly_linked_list, int);
    int(*get_element)(singly_linked_list, int);
    void(*insert)(singly_linked_list, int, int);
    void(*insert_head)(singly_linked_list, int);
    void(*insert_tail)(singly_linked_list, int);
    int(*delete_element)(singly_linked_list, int);
    void(*traverse_list)(singly_linked_list, void(*)(int));
    void(*clear)(singly_linked_list);
    void(*destroy)(singly_linked_list*);
    void(*inplace_revert)(singly_linked_list);
} singly_linked_list_operation_set;

void init_singly_linked_list_operations(void);
