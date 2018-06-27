
#include "slist.h"

#include <stdlib.h>

#define DSFUNC(func) slist_func_##func
#define INIT_DSFUNC(func) slist_operation_set.func = DSFUNC(func)

slist DSFUNC(create)(void);
int DSFUNC(get_length)(slist);
int DSFUNC(find_index)(slist, int);
int DSFUNC(get_element)(slist, int);
void DSFUNC(insert)(slist, int, int);
void DSFUNC(insert_head)(slist, int);
void DSFUNC(insert_tail)(slist, int);
void DSFUNC(delete_element)(slist, int);
void DSFUNC(traverse_list)(slist, void(*)(int));
void DSFUNC(clear)(slist);
void DSFUNC(destroy)(slist*);
void DSFUNC(inplace_revert)(slist);

void init_slist_operations(void) {
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

slist DSFUNC(create)(void) {
    return (slist)calloc(1, sizeof(slist_node));
}

int DSFUNC(get_length)(slist list) {
    if (list == NULL) { return 0; }

    slist_node* current = list->next;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int DSFUNC(find_index)(slist list, int data) {
    if (list == NULL) { return -1; }

    slist_node* current = list->next;
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

int DSFUNC(get_element)(slist list, int index) {
    if (list == NULL) { return 0; }

    slist_node* current = list->next;
    while (current != NULL && index--) {
        current = current->next;
    }
    if (index != -1) { return 0; }
    return current->data;
}

void DSFUNC(insert)(slist list, int position, int value) {
    if (list == NULL) { return; }

    int index = 0;
    slist_node* current = list;

    while (index != position) {
        index++;
        current = current->next;
        if (current == NULL) {
            return;
        }
    }
    slist_node* new_node = (slist_node*)calloc(1, sizeof(slist_node));
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
}

void DSFUNC(insert_head)(slist list, int value) {
    if (list == NULL) { return; }

    slist_node* new_node = (slist_node*)calloc(1, sizeof(slist_node));
    new_node->data = value;
    new_node->next = list->next;
    list->next = new_node;
}

void DSFUNC(insert_tail)(slist list, int value) {
    if (list == NULL) { return; }

    slist_node* new_node = (slist_node*)calloc(1, sizeof(slist_node));
    new_node->data = value;

    slist_node* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void DSFUNC(delete_element)(slist list, int index) {
    if (list == NULL) { return; }

    slist_node* current = list;
    int current_index = 0;
    while (current->next != NULL) {
        if (current_index++ == index) {
            slist_node* next = current->next->next;
            free(current->next);
            current->next = next;
            return;
        }
        current = current->next;
    }
}

void DSFUNC(traverse_list)(slist list, void(*traverse_func)(int)) {
    if (list == NULL || traverse_func == NULL) { return; }

    slist_node* current = list->next;
    while (current != NULL) {
        traverse_func(current->data);
        current = current->next;
    }
}

void DSFUNC(clear)(slist list) {
    if (list == NULL) { return; }

    slist_node* current = list->next;

    while (current != NULL) {
        list->next = current->next;
        free(current);
        current = list->next;
    }
}

void DSFUNC(destroy)(slist* plist) {
    if (plist == NULL) { return; }
    slist list = *plist;
    if (list == NULL) { return; }

    slist_node* current = list->next;
    while (current != NULL) {
        slist_node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
    *plist = NULL;
}

void DSFUNC(inplace_revert)(slist list) {
    if (list == NULL) { return; }

    slist_node* current = list->next;
    list->next = NULL;
    while (current != NULL) {
        slist_node* next = current->next;
        current->next = list->next;
        list->next = current;
        current = next;
    }
}
