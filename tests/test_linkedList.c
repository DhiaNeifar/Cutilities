#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/linkedList.h"

static void assert_array_equals(const int *actual, const int *expected, size_t n) {
    for (size_t i = 0; i < n; i++) {
        assert(actual[i] == expected[i]);
    }
}

int main(void) {
    printf("Running linked list tests...\n");

    node *head = NULL;
    const int values[] = {1, 2, 3, 4, 5};
    assert(fromArray(values, 5, &head) == LLIST_OK);
    assert(head != NULL);

    size_t length = 0;
    assert(getLength(head, &length) == LLIST_OK);
    assert(length == 5);

    int max = 0;
    int min = 0;
    double average = 0.0;
    assert(getMax(head, &max) == LLIST_OK);
    assert(max == 5);
    assert(getMin(head, &min) == LLIST_OK);
    assert(min == 1);
    assert(getAverage(head, &average) == LLIST_OK);
    assert(average == 3.0);

    node *tail = NULL;
    assert(getTail(head, &tail) == LLIST_OK);
    assert(tail != NULL && tail->value == 5);

    assert(append(head, 6) == LLIST_OK);
    assert(getTail(head, &tail) == LLIST_OK);
    assert(tail->value == 6);

    assert(insertNode(&head, 0, 0) == LLIST_OK);
    assert(head->value == 0);
    assert(insertNode(&head, 3, 99) == LLIST_OK);
    int *array = NULL;
    size_t n = 0;
    assert(toArray(head, &array, &n) == LLIST_OK);
    const int after_insert[] = {0, 1, 2, 99, 3, 4, 5, 6};
    assert(n == 8);
    assert_array_equals(array, after_insert, n);
    free(array);

    assert(removeNode(&head, 0) == LLIST_OK);
    assert(head->value == 1);
    assert(removeNode(&head, 99) == LLIST_OK);
    assert(removeNode(&head, 12345) == LLIST_VALUE_DOESNT_EXIST);

    assert(removeByIndex(&head, 0) == LLIST_OK);
    assert(head->value == 2);
    assert(removeByIndex(&head, 100) == LLIST_ERROR_OUT_OF_BOUNDS);

    int popped = 0;
    assert(pop(&head, &popped) == LLIST_OK);
    assert(popped == 6);

    node *other = NULL;
    const int other_values[] = {7, 8};
    assert(fromArray(other_values, 2, &other) == LLIST_OK);

    node *joined = NULL;
    assert(join(head, other, &joined) == LLIST_OK);
    assert(joined == head);
    assert(toArray(joined, &array, &n) == LLIST_OK);
    const int after_join[] = {2, 3, 4, 5, 7, 8};
    assert(n == 6);
    assert_array_equals(array, after_join, n);
    free(array);

    assert(deleteLinkedList(joined) == LLIST_OK);
    head = NULL;
    other = NULL;
    joined = NULL;

    node *single = NULL;
    const int single_value[] = {42};
    assert(fromArray(single_value, 1, &single) == LLIST_OK);
    assert(removeNode(&single, 42) == LLIST_OK);
    assert(single == NULL);

    assert(fromArray(single_value, 1, &single) == LLIST_OK);
    assert(pop(&single, &popped) == LLIST_OK);
    assert(popped == 42);
    assert(single == NULL);

    node *left_null_join = NULL;
    assert(fromArray(other_values, 2, &other) == LLIST_OK);
    assert(join(NULL, other, &left_null_join) == LLIST_OK);
    assert(left_null_join == other);
    assert(deleteLinkedList(left_null_join) == LLIST_OK);
    other = NULL;

    node *right_null_join = NULL;
    assert(fromArray(other_values, 2, &other) == LLIST_OK);
    assert(join(other, NULL, &right_null_join) == LLIST_OK);
    assert(right_null_join == other);
    assert(deleteLinkedList(right_null_join) == LLIST_OK);
    other = NULL;

    node *empty = NULL;
    assert(fromArray(values, 0, &empty) == LLIST_ERROR_EMPTY);
    assert(empty == NULL);
    assert(fromArray(NULL, 5, &empty) == LLIST_ERROR_NULL_ARGUMENT);
    assert(getLength(NULL, &length) == LLIST_ERROR_NULL_ARGUMENT);
    assert(getLength(head, NULL) == LLIST_ERROR_NULL_ARGUMENT);
    assert(append(NULL, 1) == LLIST_ERROR_NULL_ARGUMENT);
    assert(toArray(NULL, &array, &n) == LLIST_ERROR_NULL_ARGUMENT);
    assert(toArray(head, NULL, &n) == LLIST_ERROR_NULL_ARGUMENT);
    assert(toArray(head, &array, NULL) == LLIST_ERROR_NULL_ARGUMENT);
    assert(join(head, other, NULL) == LLIST_ERROR_NULL_ARGUMENT);
    assert(pop(NULL, &popped) == LLIST_ERROR_NULL_ARGUMENT);
    assert(pop(&empty, &popped) == LLIST_ERROR_NULL_ARGUMENT);
    assert(pop(&empty, NULL) == LLIST_ERROR_NULL_ARGUMENT);

    printf("All linked list tests passed.\n");
    return 0;
}
