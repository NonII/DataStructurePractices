
#include "SinglyLinkedList.h"

#include <stdio.h>

void print_data(int data) { printf("%d\t", data); }

#define INIT_DSOPR init_singly_linked_list_operations
#define DSOPR(opr) singly_linked_list_operation_set.opr

int main(int argc, const char* argv[]) {

    INIT_DSOPR();

    singly_linked_list list = singly_linked_list_operation_set.create();

    DSOPR(insert)(list, 0, 233);
    DSOPR(insert)(list, 1, 234);
    DSOPR(insert)(list, 2, 235);
    DSOPR(insert)(list, 0, 232);
    DSOPR(insert)(list, 2, 6666);

    DSOPR(traverse_list)(list, print_data);

    printf("\n*************************************************************\n");

    DSOPR(insert_head)(list, -1);
    DSOPR(insert_head)(list, -2);
    DSOPR(insert_head)(list, -3);
    DSOPR(insert_tail)(list, 0);
    DSOPR(insert_tail)(list, 99999);

    DSOPR(traverse_list)(list, print_data);

    printf("\n*************************************************************\n");

    print_data(DSOPR(get_length)(list));

    printf("\n*************************************************************\n");

    print_data(DSOPR(find_index)(list, 232));
    print_data(DSOPR(find_index)(list, 233));
    print_data(DSOPR(find_index)(list, 6666));
    print_data(DSOPR(find_index)(list, 234));
    print_data(DSOPR(find_index)(list, 235));
    print_data(DSOPR(find_index)(list, 239));

    printf("\n*************************************************************\n");

    print_data(DSOPR(get_element)(list, 0));
    print_data(DSOPR(get_element)(list, 1));
    print_data(DSOPR(get_element)(list, 2));
    print_data(DSOPR(get_element)(list, 3));
    print_data(DSOPR(get_element)(list, 4));
    print_data(DSOPR(get_element)(list, 5));
    print_data(DSOPR(get_element)(list, 6));

    printf("\n*************************************************************\n");

    DSOPR(delete_element)(list, 4);
    DSOPR(delete_element)(list, 4);
    DSOPR(delete_element)(list, 0);
    DSOPR(delete_element)(list, 0);

    DSOPR(traverse_list)(list, print_data);

    printf("\n*************************************************************\n");

    DSOPR(inplace_revert)(list);

    DSOPR(traverse_list)(list, print_data);

    printf("\n*************************************************************\n");

    DSOPR(clear)(list);

    print_data(DSOPR(get_length)(list));

    printf("\n*************************************************************\n");

    singly_linked_list_operation_set.destroy(&list);

    getchar();

    return 0;
}
