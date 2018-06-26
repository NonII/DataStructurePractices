
#include "SinglyLinkedList.h"

#include <stdio.h>

void print_data(int data) {
    static int count = 0;
    printf("%d\t", data);
    if (++count == 10) {
        printf("\n");
        count = 0;
    }
}

int main(int argc, const char* argv[]) {

    init_singly_linked_list_operations();
    singly_linked_list list = singly_linked_list_operation_set.create();
    singly_linked_list_operation_set.insert(list, 0, 233);
    singly_linked_list_operation_set.insert(list, 1, 234);
    singly_linked_list_operation_set.insert(list, 2, 235);
    singly_linked_list_operation_set.insert(list, 0, 232);
    singly_linked_list_operation_set.insert(list, 2, 6666);
    singly_linked_list_operation_set.traverse_list(list, print_data);
    printf("\n");
    //print_data(singly_linked_list_operation_set.get_element(list, 0));
    //print_data(singly_linked_list_operation_set.get_element(list, 1));
    //print_data(singly_linked_list_operation_set.get_element(list, 2));
    //print_data(singly_linked_list_operation_set.get_element(list, 3));
    //print_data(singly_linked_list_operation_set.get_element(list, 4));
    //print_data(singly_linked_list_operation_set.get_element(list, 5));
    //print_data(singly_linked_list_operation_set.get_element(list, 6));
    //print_data(singly_linked_list_operation_set.find_index(list, 232));
    //print_data(singly_linked_list_operation_set.find_index(list, 233));
    //print_data(singly_linked_list_operation_set.find_index(list, 6666));
    //print_data(singly_linked_list_operation_set.find_index(list, 234));
    //print_data(singly_linked_list_operation_set.find_index(list, 235));
    //print_data(singly_linked_list_operation_set.find_index(list, 239));
    //print_data(singly_linked_list_operation_set.get_length(list));

    singly_linked_list_operation_set.destroy(&list);

    getchar();

    return 0;
}
