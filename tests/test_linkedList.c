//
// Created by Dhia Neifar on 10/27/25.
//


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/linkedList.h"

int main(void) {
    printf("Running LinkedList tests...\n");

    // Test data
    const int n = 5;
    const int values[] = {1, 2, 3, 4, 5};

    // === Test createLinkedList ===
    Node *head = createLinkedList(values, n);
    assert(head != NULL && "createLinkedList returned NULL");

    // === Test getLength ===
    const size_t length = getLength(head);
    assert(length == n && "getLength() returned incorrect length");

    // === Test getMax ===
    const int maxVal = getMax(head);
    assert(maxVal == 5 && "getMax() failed to find correct maximum");

    // === Test getMin ===
    const int minVal = getMin(head);
    assert(minVal == 1 && "getMin() failed to find correct minimum");

    // === Cleanup ===
    head = delLinkedList(head);
    assert(head == NULL && "delLinkedList() did not clean up properly");

    return 0;  // required: CTest uses this exit code (0 = success)
}
