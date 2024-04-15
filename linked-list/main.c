#include "stdio.h"
#include "stdlib.h"
#include "headers/nodes.h"

int main()
{
    /*
    initialise a linkedlist with 3 nodes
    using push to add to last in list
    */
    struct Node* head = create_node();

    head->value = 0;
    // free(head->next_node);
    // free(head);
    push(head, 1);
    push(head, 2);
    push(head, 3);
    print_list(head); 

    /*
    pop the last node in linkedlist
    */
    pop(&head);
    print_list(head);


    // /*
    // append node in the middle of the list
    // append node at the start of the list
    // */
    append_at_index(&head, 1, 4);
    print_list(head);

    append_at_index(&head, 0, 5);
    print_list(head);

    // /*
    // remove node at the middle of the list
    // remove node at the start of the list
    // */
    remove_at_index(&head, 2);
    print_list(head);

    remove_at_index(&head, 0);
    print_list(head);

    /*
    error handling - bad inputs
    */

    free_node_mem(head);

    return 0;
}
