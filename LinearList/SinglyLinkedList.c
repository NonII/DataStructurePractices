
#include "SinglyLinkedList.h"

#include <stdlib.h>

#define DSFUNC(func) singly_linked_list_func_##func
#define INIT_DSFUNC(func) singly_linked_list_operation_set.##func = DSFUNC(func)

singly_linked_list DSFUNC(create)(void);
int DSFUNC(get_length)(singly_linked_list);
int DSFUNC(find_index)(singly_linked_list, int);
int DSFUNC(get_element)(singly_linked_list, int);
void DSFUNC(insert)(singly_linked_list, int, int);
void DSFUNC(insert_head)(singly_linked_list, int);
void DSFUNC(insert_tail)(singly_linked_list, int);
void DSFUNC(delete_element)(singly_linked_list, int);
void DSFUNC(traverse_list)(singly_linked_list, void(*)(int));
void DSFUNC(clear)(singly_linked_list);
void DSFUNC(destroy)(singly_linked_list*);
void DSFUNC(inplace_revert)(singly_linked_list);

void init_singly_linked_list_operations(void) {
    INIT_DSFUNC(create);
    INIT_DSFUNC(get_length);
    INIT_DSFUNC(find_index);
    INIT_DSFUNC(get_element);
    INIT_DSFUNC(insert);
    INIT_DSFUNC(insert_head);
    INIT_DSFUNC(insert_tail);
    INIT_DSFUNC(delete_element);
    INIT_DSFUNC(traverse_list);
    INIT_DSFUNC(clear);
    INIT_DSFUNC(destroy);
    INIT_DSFUNC(inplace_revert);
}

singly_linked_list DSFUNC(create)(void) {
    return (singly_linked_list)calloc(1, sizeof(singly_linked_list_node));
}

int DSFUNC(get_length)(singly_linked_list list) {
    if (list == NULL) { return 0; }

    singly_linked_list_node* current = list->next;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int DSFUNC(find_index)(singly_linked_list list, int data) {
    if (list == NULL) { return -1; }

    singly_linked_list_node* current = list->next;
    int index = 0;
    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        index++;
        current = current->next;
    }

    return -1;
}

int DSFUNC(get_element)(singly_linked_list list, int index) {
    if (list == NULL) { return 0; }

    singly_linked_list_node* current = list->next;
    while (current != NULL && index--) {
        current = current->next;
    }
    if (index != -1) { return 0; }
    return current->data;
}

void DSFUNC(insert)(singly_linked_list list, int position, int value) {
    if (list == NULL) { return; }

    int index = 0;
    singly_linked_list_node* current = list;

    while (index != position) {
        index++;
        current = current->next;
        if (current == NULL) {
            return;
        }
    }
    singly_linked_list_node* new_node = (singly_linked_list_node*)calloc(1, sizeof(singly_linked_list_node));
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
}

void DSFUNC(insert_head)(singly_linked_list list, int value) {
    if (list == NULL) { return; }

    singly_linked_list_node* new_node = (singly_linked_list_node*)calloc(1, sizeof(singly_linked_list_node));
    new_node->data = value;
    new_node->next = list->next;
    list->next = new_node;
}

void DSFUNC(insert_tail)(singly_linked_list list, int value) {
    if (list == NULL) { return; }

    singly_linked_list_node* new_node = (singly_linked_list_node*)calloc(1, sizeof(singly_linked_list_node));
    new_node->data = value;

    singly_linked_list_node* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void DSFUNC(delete_element)(singly_linked_list list, int index) {
    if (list == NULL) { return; }

    singly_linked_list_node* current = list;
    int current_index = 0;
    while (current->next != NULL) {
        if (current_index++ == index) {
            singly_linked_list_node* next = current->next->next;
            free(current->next);
            current->next = next;
            return;
        }
        current = current->next;
    }
}

void DSFUNC(traverse_list)(singly_linked_list list, void(*traverse_func)(int)) {
    if (list == NULL || traverse_func == NULL) { return; }

    singly_linked_list_node* current = list->next;
    while (current != NULL) {
        traverse_func(current->data);
        current = current->next;
    }
}

void DSFUNC(clear)(singly_linked_list list) {
    if (list == NULL) { return; }

    singly_linked_list_node* current = list->next;

    while (current != NULL) {
        list->next = current->next;
        free(current);
        current = list->next;
    }
}

void DSFUNC(destroy)(singly_linked_list* plist) {
    if (plist == NULL) { return; }
    singly_linked_list list = *plist;
    if (list == NULL) { return; }

    singly_linked_list_node* current = list->next;
    while (current != NULL) {
        singly_linked_list_node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
    *plist = NULL;
}

void DSFUNC(inplace_revert)(singly_linked_list list) {
    if (list == NULL) { return; }

    singly_linked_list_node* current = list->next;
    list->next = NULL;
    while (current != NULL) {
        singly_linked_list_node* next = current->next;
        current->next = list->next;
        list->next = current;
        current = next;
    }
}
