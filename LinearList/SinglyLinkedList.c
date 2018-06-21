
#include "SinglyLinkedList.h"

#include <stdlib.h>

singly_linked_list create(void);
void insert(singly_linked_list, int, int);
void insert_head(singly_linked_list, int);
void insert_tail(singly_linked_list, int);

void init_singly_linked_list_operations(void) {
    singly_linked_list_operation_set.create = create;
}

singly_linked_list create(void) {
    return (singly_linked_list)calloc(1, sizeof(singly_linked_list_node));
}

void insert(singly_linked_list list, int position, int value) {
    int i = 0;
    singly_linked_list_node * current_node = list;

    while (i != position && current_node != NULL) {

    }
}

void insert_head(singly_linked_list list, int value) {

}

void insert_tail(singly_linked_list list, int value) {

}
