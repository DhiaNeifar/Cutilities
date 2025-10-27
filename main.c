//
// Created by Dhia Neifar on 10/26/25.
//


#include "include/linkedList.h"

#include <stdlib.h>

int main(void) {
    const int n = 5;
    const int array[] = {1, 2, 3, 4, 5};

    Node *head = createLinkedList(array, n);
    iterateLinkedList(head);


    // Testing Append
    head = append(head, 6);
    iterateLinkedList(head);


     // Testing Remove
    head = removeNode(head, 1);
    iterateLinkedList(head);


    // Testing Pop
    Node *popped = pop(head);
    free(popped);
    iterateLinkedList(head);


    head = delLinkedList(head);
    return 0;
}