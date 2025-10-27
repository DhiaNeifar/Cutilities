//
// Created by Dhia Neifar on 10/26/25.
//


#include "include/linkedList.h"

int main(void) {
    const int n = 5;
    const int array[] = {1, 2, 3, 4, 5};

    Node *head = createLinkedList(n, array);
    iterateLinkedList(head);


    // Testing Append
    head = append(6, head);
    iterateLinkedList(head);


     // Testing Remove
    head = removeNode(1, head);
    iterateLinkedList(head);


    // Testing Pop
    Node *popped = pop(head);
    iterateLinkedList(head);


    head = delLinkedList(head);
    return 0;
}