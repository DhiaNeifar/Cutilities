#include "include/linkedList.h"

#include <stdio.h>
#include <stdlib.h>

static void print_status(const char *label, const LListStatus status) {
    printf("%s: %d\n", label, status);
}

int main(void) {
    const int values[] = {10, 20, 30};
    node *head = NULL;

    const LListStatus status = fromArray(values, 3, &head);
    print_status("fromArray", status);
    if (status != LLIST_OK) return 1;

    printf("Initial list: ");
    iterateLinkedList(head);

    append(head, 40);
    printf("After append 40: ");
    iterateLinkedList(head);

    insertNode(&head, 0, 5);
    printf("After insert 5 at index 0: ");
    iterateLinkedList(head);

    removeNode(&head, 20);
    printf("After remove value 20: ");
    iterateLinkedList(head);

    int popped = 0;
    pop(&head, &popped);
    printf("Popped value: %d\n", popped);
    printf("After pop: ");
    iterateLinkedList(head);

    size_t length = 0;
    int max = 0;
    int min = 0;
    double average = 0.0;
    getLength(head, &length);
    getMax(head, &max);
    getMin(head, &min);
    getAverage(head, &average);
    printf("length=%zu max=%d min=%d average=%.2f\n", length, max, min, average);

    int *array = NULL;
    size_t n = 0;
    if (toArray(head, &array, &n) == LLIST_OK) {
        printf("Array copy:");
        for (size_t i = 0; i < n; i++) {
            printf(" %d", array[i]);
        }
        printf("\n");
        free(array);
    }

    deleteLinkedList(head);
    return 0;
}
